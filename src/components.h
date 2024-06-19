#pragma once
#include <raylib.h>
#include "texture_pool.h"
#include "types.h"


#define ZE_NUM_COMPONENTS (3)


namespace ze{
	

	typedef struct transform {
		Vector2 pos{};
		Vector2 size{};
		Vector2 direction{};
		Vector2 lastMovement{};
		ze::Zindex zIndex = 0;
		float rotation = 0.0f;
		float speed = 0.0f;
		transform() = default;
		transform(
			const ze::Zindex zIndex
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

}