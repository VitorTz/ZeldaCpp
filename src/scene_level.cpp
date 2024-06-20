#include "scene.h"
#include "ecs.h"
#include <random>



void level_scene_test() {
	std::default_random_engine g;
	std::uniform_real_distribution<float> randXPos(0, ZE_SCREEN_WIDTH);
	std::uniform_real_distribution<float> randYPos(-ZE_SCREEN_HEIGHT, 0);
	std::uniform_real_distribution<float> randSpeed(30.f, 150.f);

	for (int i = 0; i < ZE_MAX_ENTITIES; i++) {
		const ze::entity e = ze::gEcs.entityCreate(0, true);
		ze::gEcs.addComponent<ze::sprite_t>(e, ze::sprite_t{ ASSETS_PATH "icon/icon.png" });
		ze::transform_t& t = ze::gEcs.get_transform(e);
		t.direction.y = 1.f;
		t.speed = randSpeed(g);
		t.rect.x = randXPos(g);
		t.rect.y = randYPos(g);		
	}
}


static ze::entity load_sprite(
	const float posX,
	const float posY,
	const ze::z_index zIndex, 
	const char* sprite_file	
) {
	const ze::entity e = ze::gEcs.entityCreate(zIndex, true);
	ze::gEcs.addComponent<ze::sprite_t>(e, ze::sprite_t{ sprite_file });
	ze::transform_t& t = ze::gEcs.get_transform(e);
	t.rect.x = posY * ZE_TILE_SIZE;	
	t.rect.y = posX * ZE_TILE_SIZE;
	t.rect.width = ZE_TILE_SIZE;
	t.rect.height = ZE_TILE_SIZE;
	return e;
}


ze::LevelScene::LevelScene() {	
	ze::entity new_entity{};

	// CREATE MAP	
	for (int i = 0; i < ZE_WORLD_MAP_ROWS; i++) {
		for (int j = 0; j < ZE_WORLD_MAP_COLS; j++) {			
			switch (WORLD_MAP[i][j]) {
				case 'x': // rock
					new_entity = load_sprite(i, j, 1, ASSETS_PATH "graphics/test/rock.png");
					ze::gEcs.addComponent<ze::obstacle_t>(new_entity, ze::obstacle_t{});
					break;
				case 'p': // player					
					new_entity = load_sprite(i, j, 1, ASSETS_PATH "graphics/test/player.png");
					ze::gEcs.addComponent<ze::player_t>(new_entity, ze::player_t{});
					ze::gEcs.addComponent<ze::controller_t>(new_entity, ze::controller_t{});
					ze::gEcs.addComponent<ze::obstacle_t>(new_entity, ze::obstacle_t{ {0.8f, 0.5f} });
					ze::gEcs.get_transform(new_entity).speed = ZE_PLAYER_SPEED;
					break;
				default:
					break;
			}
		}
	}

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