#pragma once
#include <raylib.h>
#include "texture_pool.h"
#include "types.h"


#define ZE_NUM_COMPONENTS (6)


namespace ze{
	

	typedef struct transform {
		Rectangle rect = { 0.0f, 0.0f, 0.0f, 0.0f };
		Vector2 direction = { 0.0f, 0.0f };
		Vector2 lastMovement = { 0.0f, 0.0f };
		ze::z_index zIndex = 0;		
		float speed = 0.0f;
		transform() = default;		
		transform(
			const ze::z_index zIndex
		) : zIndex(zIndex) { }
	} transform_t; 

	typedef struct sprite {
		Texture2D texture;
		sprite() = default;		
		sprite(
			const char* file_name
		) : texture(ze::gTexturePool.load(file_name)) { }
	} sprite_t;

	typedef struct sprite_animation {
		Texture2D texture;
		Rectangle rect;
		std::uint8_t speed = 0;
		std::uint8_t current_frame = 0;
		std::uint8_t frame_counter = 0;
		std::uint8_t max_frames = 0;
		sprite_animation() = default;
		sprite_animation(
			const char* file_name,
			const float sprite_width,
			const ze::AnimationSpeed animation_speed
		) : texture(ze::gTexturePool.load(file_name)),
			rect({0.0f, 0.0f, sprite_width, (float) texture.height}),
			speed(60 / static_cast<int>(animation_speed) ),
			max_frames(static_cast<std::uint8_t>(texture.width / rect.width)) {

		}
	} sprite_animation_t;

	typedef struct controller {
			
	} controller_t;

	typedef struct obstacle {		
		Rectangle rect = { 0.0f, 0.0f, 0.0f, 0.0f };
		Vector2 scale = { 1.0f, 1.0f };
		obstacle(const Vector2 scale) : scale(scale) { }
		obstacle() = default;
	} obstacle_t;

	typedef struct player {
		ze::Action action = ze::DownIdle;
	} player_t;

}