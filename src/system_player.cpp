#include "system.hpp"
#include "ecs.hpp"
#include <raymath.h>
#include <iostream>


void ze::PlayerSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {        
        ze::transform_t& transform = ze::gEcs.getTransform(e);                
        ze::player_t& player = ze::gEcs.getComponent<ze::player_t>(e, ze::PlayerId);
        
        const char lastDirectionX = player.direction[0];
        const char lastDirectionY = player.direction[1];
        const char lastAction = player.action;
        std::string animation_path = "assets/graphics/player/";

        switch (player.action) {
            case 'x': // not attacking
                player.action = IsKeyPressed(KEY_SPACE) ? 'a' : player.action;
                player.attack_timer = 0.0f;
                player.direction[0] = (transform.direction.x == 0.0f && transform.direction.y == 0.0f) ? 'i' : 'm';
                if (transform.direction.y < 0) {
                    player.direction[1] = 'u';                    
                } else if (transform.direction.y > 0) {
                    player.direction[1] = 'd';                    
                }
                if (transform.direction.x > 0) {
                    player.direction[1] = 'r';                    
                } else if (transform.direction.x < 0) {
                    player.direction[1] = 'l';                    
                }                
                break;
            case 'a': // attack
                player.attack_timer += dt;
                player.action = player.attack_timer >= ZE_PLAYER_ATTACK_SPEED ? 'x' : player.action;                
                break;
            default:
                break;
        }

        // animation
        if (
            lastAction != player.action || 
            lastDirectionX != player.direction[0] || 
            lastDirectionY != player.direction[1]
        ) {
            animation_path += player.direction[0];
            animation_path += player.direction[1];            
            if (player.action != 'x') animation_path += player.action;
            animation_path += ".png";            
            player.animation.changeTexture(animation_path.c_str());            
        }

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
        if (ze::gEcs.checkCollision(e).second == true || player.action == 'a') {            
            transform.rect.x -= transform.lastMovement.x;
            transform.rect.y -= transform.lastMovement.y;
            transform.lastMovement.x = 0.0f;
            transform.lastMovement.y = 0.0f;
        }
    }
}


void ze::PlayerSystem::draw(const ze::entity_t e) {
    const ze::transform_t& t = ze::gEcs.getTransform(e);
    const ze::player_t& p = ze::gEcs.getComponent<ze::player_t>(e, ze::PlayerId);    
    DrawTextureRec(p.animation.texture, p.animation.rect, { t.rect.x, t.rect.y }, WHITE);
    if (p.action == 'a') {        
        std::string path = "assets/graphics/weapons/";        
        Vector2 offset = {0.0f, 0.0f};

        switch (p.weapon) {
            case ze::Axe:
                path.append("axe/");                
                break;
            case ze::Sword:
                path.append("sword/");                
                break;
            case ze::Lance:
                path.append("lance/");                
                break;
            case ze::Sai:
                path.append("sai/");
                break;            
            default:
                break;
        }        
        switch (p.direction[1]) {
            case 'd':                
                offset.y = 30.0f;
                break;
            case 'l':
                offset.x = -75.0f;
                offset.y = 5.0;
                break;
            case 'u':                
                offset.y = -75.0f;
                offset.x = -25.0f;
                break;
            case 'r':
                offset.x = 30.0f;
                offset.y = 5.0;
                break;
            default:
                break;
        }

        path += p.direction[1];
        path += ".png";
        DrawTextureV(
            ze::gTexturePool.load(path.c_str()), 
            {ZE_SCREEN_CENTERX + offset.x, ZE_SCREEN_CENTERY + offset.y},            
            WHITE
        );
    }
}