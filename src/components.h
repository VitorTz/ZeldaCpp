#pragma once
#include <raylib.h>
#include "texture_pool.h"
#include "types.h"


#define ZE_NUM_COMPONENTS (5)


namespace ze{
	

	typedef struct transform {
		Rectangle rect = { 0.0f, 0.0f, 0.0f, 0.0f };
		Vector2 direction = { 0.0f, 0.0f };
		Vector2 lastMovement = { 0.0f, 0.0f };
		ze::z_index zIndex = 0;
		float rotation = 0.0f;
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

	typedef struct controller {
			
	} controller_t;

	typedef struct obstacle {
		Vector2 shrinkScale = { 1.0f, 1.0f };
	} obstacle_t;

	typedef struct player {

	} player_t;

}