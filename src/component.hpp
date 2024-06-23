#ifndef ZELDA_COMPONENT_HPP
#define ZELDA_COMPONENT_HPP
#include <raylib.h>
#include <cstdint>
#include "constants.hpp"
#include "texture_pool.hpp"
#include "types.hpp"


#define ZE_NUM_COMPONENTS (6)


namespace ze {


    enum ComponentId {
        SpriteId,
        TransformId,
        ObstacleId,
        ControllerId,        
        AnimationId,
        PlayerId
    };

    typedef struct transform {
        Rectangle rect = {0.0f, 0.0f, 0.0f, 0.0f};        
        Vector2 direction = {0.0f, 0.0f};
        Vector2 lastMovement = {0.0f, 0.0f};
        char directionChar[2] = {'i', 'd'};
        float speed = 0.0f;
        ze::zindex_t z_index = 0;
        transform() = default;
        transform(const ze::zindex_t z_index) : z_index(z_index) { }
    } transform_t;

    typedef struct sprite {
        Texture2D texture{};
        sprite() = default;
        sprite(const char* file_name) : texture(ze::gTexturePool.load(file_name)) {

        }
    } sprite_t;

    typedef struct obstacle {
        Vector2 hitbox = {1.0f, 1.0f};
        Rectangle rect = {0.0f, 0.0f, 0.0f, 0.0f};
        obstacle(const Vector2 hitbox) : hitbox(hitbox) {  }
        obstacle() = default;
    } obstacle_t;

    typedef struct controller {

    } controller_t;        

    typedef struct animation {
        Texture2D texture{};
        Rectangle rect{};
        std::uint8_t current_frame = 0;
        std::uint8_t frame_counter = 0;
        std::uint8_t speed = 0;
        std::uint8_t max_frames = 0;
        animation() = default;
        animation(
            const char* file_name, 
            const float sprite_width, 
            const ze::AnimationSpeed _speed
        ) : texture(ze::gTexturePool.load(file_name)),
            rect({0.0f, 0.0f, sprite_width, (float) texture.height}),
            speed(60 / (int) _speed),
            max_frames(texture.width / sprite_width) { } 
        animation(
            const float sprite_width, 
            const float sprite_height, 
            const ze::AnimationSpeed _speed
        ) : rect({0.0f, 0.0f, sprite_width, sprite_height}),
            speed(60 / (int) _speed) { }
        void changeTexture(const char* file_name) {            
            this->texture = ze::gTexturePool.load(file_name);
            this->rect.x = 0;
            this->current_frame = 0;
            this->frame_counter = 0;
            this->max_frames = this->texture.width / this->rect.width;            
        }
    } animation_t;    

    typedef struct player {
        char lastDirection[2] = {'i', 'd'};       
        char action = 'x';
        float attack_timer = 0.0f;
        ze::animation_t animation = ze::animation_t{
            static_cast<float>(ZE_TILE_SIZE), 
            static_cast<float>(ZE_TILE_SIZE),            
            ze::Normal
        };
        ze::Weapon weapon = ze::Sword;        
    } player_t;

}

#endif