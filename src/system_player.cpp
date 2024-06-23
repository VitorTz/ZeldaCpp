#include "system.hpp"
#include "ecs.hpp"
#include "weapons.hpp"
#include "globals.hpp"
#include <raymath.h>
#include <iostream>


static Texture2D get_weapon_texture(const ze::Weapon weapon, const char direction) {
    Texture2D t{};
    std::string s = "assets/graphics/weapons/";
    switch (weapon) {
        case ze::Axe:            
            s.append("axe/");                
            break;
        case ze::Sword:
            s.append("sword/");                
            break;
        case ze::Lance:
            s.append("lance/");                
            break;
        case ze::Sai:
            s.append("sai/");
            break;        
        default:
            break;
    }
    s += direction;
    s.append(".png");
    t = ze::gTexturePool.load(s.c_str());    
    return t;
}


void ze::PlayerSystem::update([[maybe_unused]] const float dt) {    
    ze::transform_t& transform = ze::gEcs.getTransform(ze::globals::playerEntity);
    ze::player_t& player = ze::gEcs.getComponent<ze::player_t>(ze::globals::playerEntity, ze::PlayerId);    
    
    const char lastAction = player.action;    
    std::string animation_path = "assets/graphics/player/";

    player.attack_timer = player.action == 'a' ?  player.attack_timer + dt : 0.0f;

    // player state
        switch (player.action) {
            case 'x': // moving
                player.action = IsKeyPressed(KEY_SPACE) ? 'a' : player.action;
                player.weapon = IsKeyPressed(KEY_Z) ? static_cast<ze::Weapon>(((int) player.weapon + 1) % 4) : player.weapon;
                break;
            case 'a': // attack
                player.action = player.attack_timer >= ZE_PLAYER_ATTACK_SPEED ? 'x' : player.action;                
                break;
            default:
                break;
        }

    // animation
        if (
            player.lastDirection[0] != transform.directionChar[0] || 
            player.lastDirection[1] != transform.directionChar[1] ||
            lastAction != player.action
        ) {
            animation_path += transform.directionChar[0];
            animation_path += transform.directionChar[1];
            if (player.action != 'x') animation_path += player.action;
            animation_path += ".png";       
            player.animation.changeTexture(animation_path.c_str());            
        }

        player.lastDirection[0] = transform.directionChar[0];
        player.lastDirection[1] = transform.directionChar[1];

        player.animation.frame_counter++;        
        if (player.animation.frame_counter > player.animation.speed) {
            player.animation.frame_counter = 0;
            player.animation.current_frame++;
            if (player.animation.current_frame >= player.animation.max_frames) {
                player.animation.current_frame = 0;
                player.animation.rect.x = 0;
            }
            player.animation.rect.x += player.animation.rect.width;
        }
    
    // collision    
        // entity collision
        if (ze::gEcs.checkCollision(ze::globals::playerEntity).second == true) {
            transform.rect.x -= transform.lastMovement.x;
            transform.rect.y -= transform.lastMovement.y;
            transform.lastMovement = {0.0f, 0.0f};
        }
        // weapon collision
        if (player.action == 'a') {

        }
}


void ze::PlayerSystem::draw(const ze::entity_t e) {
    const ze::transform_t& t = ze::gEcs.getTransform(e);
    const ze::player_t& p = ze::gEcs.getComponent<ze::player_t>(e, ze::PlayerId);    
    DrawTextureRec(p.animation.texture, p.animation.rect, { t.rect.x, t.rect.y }, WHITE);
    if (p.action == 'a') {        
        std::string path = "assets/graphics/weapons/";        
        Vector2 offset = ze::WEAPON_OFFSET.at(t.directionChar[1]);
        Vector2 weaponSize = ze::get_weapon_size(t.directionChar[1], p.weapon);        
        DrawTextureV(
            get_weapon_texture(p.weapon, t.directionChar[1]), 
            {ZE_SCREEN_CENTERX + offset.x, ZE_SCREEN_CENTERY + offset.y},
            WHITE
        );         
        // DrawRectangleV(
        //     {ZE_SCREEN_CENTERX + offset.x, ZE_SCREEN_CENTERY + offset.y}, 
        //     weaponSize, 
        //     Color{255, 0, 0, 120}
        // );
    }
}