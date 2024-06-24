#include <iostream>
#include "system.hpp"
#include "player.hpp"
#include "globals.hpp"
#include "weapon.hpp"
#include "texture_pool.hpp"
#include "ecs.hpp"


std::pair<ze::entity_t, bool> movementCollision;
Rectangle weapon_rect;
std::string animation_path;
char lastState[3];


void ze::PlayerSystem::update(const float dt) {    
    ze::transform_t& playerTransform = ze::gEcs.getTransform(ze::gPlayer.playerEntity);
    ze::sprite_animation_t& playerAnimation = ze::gEcs.getComponent<ze::sprite_animation_t>(ze::gPlayer.playerEntity);
    ze::sprite_t& playerWeaponSprite = ze::gEcs.getComponent<ze::sprite_t>(ze::gPlayer.playerWeaponEntity);
    ze::transform_t& playerWeaponTransform = ze::gEcs.getTransform(ze::gPlayer.playerWeaponEntity);
    ze::globals::camera_offset = {
        playerTransform.pos.x + playerTransform.size.x / 2.f - ZE_SCREEN_CENTERX,
        playerTransform.pos.y + playerTransform.size.y / 2.f - ZE_SCREEN_CENTERY
    };

    lastState[0] = ze::gPlayer.direction[0];
    lastState[1] = ze::gPlayer.direction[1];
    lastState[2] = ze::gPlayer.action;    
    
    switch (ze::gPlayer.action) {
        case 'a': // attacking
            playerTransform.direction = {0.0f, 0.0f};
            ze::gPlayer.attack_timer += dt;
            ze::gPlayer.action = ze::gPlayer.attack_timer >= ZE_PLAYER_ATTACK_SPEED ? 'm' : 'a';
            weapon_rect = ze::weapon_get_rect(playerTransform.pos, ze::gPlayer.direction[1], ze::gPlayer.weapon);
            playerWeaponSprite.texture = ze::gWeaponTextureMap[ze::gPlayer.weapon][ze::gPlayer.direction[1]];
            std::cout << playerWeaponSprite.texture.id << '\n';
            playerWeaponTransform.pos = {weapon_rect.x, weapon_rect.y};
            playerWeaponTransform.size = {weapon_rect.width, weapon_rect.height};
            break;
        case 'm': // moving
            if (IsKeyPressed(KEY_Z)) {
                ze::gPlayer.weapon = (ze::Weapon) ((ze::gPlayer.weapon + 1) % 4);
            }

            playerWeaponSprite.texture = {};
            playerTransform.direction = {0.0f, 0.0f};
            ze::gPlayer.attack_timer = 0.0f;
            ze::gPlayer.direction[0] = 'i';
            if (IsKeyDown(KEY_LEFT)) {
                playerTransform.direction.x = -1.0f;
                ze::gPlayer.direction[0] = 'm';
                ze::gPlayer.direction[1] = 'l';
            } else if (IsKeyDown(KEY_RIGHT)) {
                playerTransform.direction.x = 1.0f;;
                ze::gPlayer.direction[0] = 'm';
                ze::gPlayer.direction[1] = 'r';
            }
            if (IsKeyDown(KEY_UP)) {
                playerTransform.direction.y  = -1.0f;
                ze::gPlayer.direction[0] = 'm';
                ze::gPlayer.direction[1] = 'u';
            } else if (IsKeyDown(KEY_DOWN)) {
                playerTransform.direction.y = 1.0f;;
                ze::gPlayer.direction[0] = 'm';
                ze::gPlayer.direction[1] = 'd';
            }

            // movement collision
            ze::gPlayer.collideBox.x = playerTransform.pos.x + 8;
            ze::gPlayer.collideBox.y = playerTransform.pos.y + 8;
            movementCollision = ze::gEcs.checkCollision(ze::gPlayer.playerEntity, ze::gPlayer.collideBox);
            if (movementCollision.second) {
                playerTransform.pos = ze::gPlayer.lastPos;            
            } else {
                ze::gPlayer.lastPos = playerTransform.pos;
            }
            ze::gPlayer.action = IsKeyPressed(KEY_SPACE) ? 'a' : 'm';
            break;
        default:
            break;
    }    
    
    // animation
    if (
        ze::gPlayer.direction[0] != lastState[0] ||
        ze::gPlayer.direction[1] != lastState[1] ||
        ze::gPlayer.action != lastState[2]
    ) {
        // change animation            
        animation_path = "assets/graphics/player/";
        animation_path += ze::gPlayer.direction[0];
        animation_path += ze::gPlayer.direction[1];
        if (ze::gPlayer.action != 'm') animation_path += ze::gPlayer.action;
        animation_path += ".png";
        playerAnimation.texture = ze::gTexturePool.load(animation_path.c_str());
        playerAnimation.max_frames = playerAnimation.texture.width / playerAnimation.rect.width;
        playerAnimation.current_frame = 0;
        playerAnimation.frame_counter = 0;            
    }
}


void ze::PlayerSystem::draw(const ze::entity_t e) {
    const ze::transform_t& t = ze::gEcs.getTransform(ze::gPlayer.playerEntity);
    const Rectangle rect = ze::gPlayer.collideBox;
    const Vector2 offset = ze::globals::camera_offset;
    DrawRectangleLines(t.pos.x - offset.x, t.pos.y - offset.y, ZE_TILE_SIZE, ZE_TILE_SIZE, RED);
    DrawRectangleLines(rect.x - offset.x, rect.y - offset.y, ze::gPlayer.collideBox.width, ze::gPlayer.collideBox.height, BLUE);
    
    if (ze::gPlayer.action == 'a') {
        Rectangle weapon_rect = ze::weapon_get_rect(
            t.pos,
            ze::gPlayer.direction[1],
            ze::gPlayer.weapon
        );
        weapon_rect.x -= offset.x;
        weapon_rect.y -= offset.y;
        DrawRectangleRec(weapon_rect, BLUE);
    }

}