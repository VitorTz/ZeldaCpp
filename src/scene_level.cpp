#include "scene.h"
#include "ecs.h"
#include "globals.h"


static ze::entity load_sprite(
	const int posX,
	const int posY,
	const ze::z_index zIndex, 
	const char* sprite_file	
) {
	const ze::entity e = ze::gEcs.entityCreate(zIndex, true);
	ze::gEcs.addComponent<ze::sprite_t>(e, ze::sprite_t{ sprite_file });
	ze::transform_t& t = ze::gEcs.get_transform(e);
	t.rect.x = (float) posY * ZE_TILE_SIZE;	
	t.rect.y = (float) posX * ZE_TILE_SIZE;
	t.rect.width = ZE_TILE_SIZE;
	t.rect.height = ZE_TILE_SIZE;
	return e;
}


void create_map() {	
	ze::entity e{};
	for (int i = 0; i < ZE_WORLD_MAP_ROWS; i++) {
		for (int j = 0; j < ZE_WORLD_MAP_COLS; j++) {
			switch (ze::WORLD_MAP[i][j]) {
			case 'x': // rock
				e = load_sprite(i, j, 1, ASSETS_PATH "graphics/test/rock.png");
				ze::gEcs.addComponent<ze::obstacle_t>(e, ze::obstacle_t{});
				break;
			case 'p': // player					
				e = load_sprite(i, j, 1, ASSETS_PATH "graphics/test/player.png");
				ze::gEcs.addComponent<ze::player_t>(e, ze::player_t{});
				ze::gEcs.addComponent<ze::controller_t>(e, ze::controller_t{});
				ze::gEcs.addComponent<ze::obstacle_t>(e, ze::obstacle_t{ {0.8f, 0.5f} });
				ze::gEcs.get_transform(e).speed = ZE_PLAYER_SPEED;				
				ze::gPlayerEntity = e;
				break;
			default:
				break;
			}
		}
	}
}


ze::LevelScene::LevelScene() {	
	create_map();
}


void ze::LevelScene::update(const ze::ChangeScene& changeScene) {
	const float dt = GetFrameTime();	
	ze::gEcs.update(dt);
}


void ze::LevelScene::draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	ze::gEcs.draw();
	DrawFPS(10, 10);
	EndDrawing();
}