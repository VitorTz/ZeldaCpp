#ifndef ZELDA_COMPONENT_HPP
#define ZELDA_COMPONENT_HPP
#include <raylib.h>
#include "types.hpp"


#define ZE_NUM_COMPONENTS (4)

namespace ze {
    
    typedef struct transform {
        Vector2 pos;
        Vector2 size;
        Vector2 direction;
        float speed;
        ze::zindex_t zindex;
    } transform_t;

    typedef struct sprite {
        Texture2D texture;
    } sprite_t;

    typedef struct sprite_animation {
        Texture2D texture;
        Rectangle rect;
        std::uint8_t current_frame;
        std::uint8_t frame_counter;
        std::uint8_t max_frames;
        std::uint8_t speed;
        sprite_animation() = default;
        sprite_animation(
            Texture2D texture,
            const float sprite_width,
            const std::uint8_t speed
        ) : texture(std::move(texture)),
            rect({0.0f, 0.0f, sprite_width, (float) texture.height}),
            speed(speed),
            max_frames(rect.width / sprite_width) {

            }        
    } sprite_animation_t;

    typedef struct obstacle {
        Rectangle rect;
        Vector2 hitbox;
    } obstacle_t; 

} // namespace ze



#endif