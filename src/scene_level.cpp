#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <random>
#include "scene.h"
#include "ecs.h"
#include "globals.h"


static ze::entity load_normal_sprite(
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


static void load_collide_sprite(
	const int posX,
	const int posY,
	const ze::z_index zIndex,
	const char* sprite_file
) {
	const ze::entity e = ze::gEcs.entityCreate(zIndex, true);
	ze::gEcs.addComponent<ze::sprite_t>(e, ze::sprite_t{ sprite_file });
	ze::gEcs.addComponent<ze::obstacle_t>(e, ze::obstacle_t{});
;	ze::transform_t& t = ze::gEcs.get_transform(e);
	t.rect.x = (float)posY * ZE_TILE_SIZE;
	t.rect.y = (float)posX * ZE_TILE_SIZE;
	t.rect.width = ZE_TILE_SIZE;
	t.rect.height = ZE_TILE_SIZE;	
}


static void load_player() {
	const ze::entity player = ze::gEcs.entityCreate(1, true);
	ze::gEcs.addComponent<ze::player_t>(player, ze::player_t{});
	ze::gEcs.addComponent<ze::controller_t>(player, ze::controller_t{});
	ze::gEcs.addComponent<ze::obstacle_t>(player, ze::obstacle_t{ {0.6f, 0.5f} });
	ze::gEcs.addComponent<ze::sprite_animation_t>(player, ze::sprite_animation_t{ ASSETS_PATH "graphics/player/idle_down.png", ZE_TILE_SIZE, ze::Normal });
	ze::transform_t& t = ze::gEcs.get_transform(player);
	t.rect.x = ZE_PLAYER_X_POS;
	t.rect.y = ZE_PLAYER_Y_POS;
	t.rect.width = ZE_TILE_SIZE;
	t.rect.height = ZE_TILE_SIZE;
	t.speed = ZE_PLAYER_SPEED;
	ze::gPlayerEntity = player;
}


static void load_floor_block(const int posX, const int posY) {
	const ze::entity e = ze::gEcs.entityCreate(0, false);
	ze::transform_t& t = ze::gEcs.get_transform(e);
	ze::gEcs.addComponent<ze::obstacle_t>(e, ze::obstacle_t{ {0.8f, 0.8f} });
	t.rect.x = posY * ZE_TILE_SIZE;
	t.rect.y = posX * ZE_TILE_SIZE;
	t.rect.width = ZE_TILE_SIZE;
	t.rect.height = ZE_TILE_SIZE;
}


static void read_csv_file(const char* file_name) {
	int i = 0, j = 0;
	std::ifstream file(file_name, std::ifstream::in);
	std::string line, num;		

	if (file.is_open() == false) {
		std::cerr << " ==> [ERROR WHILE OPENING " << file_name << "MAP]" << '\n';
		ze::gTexturePool.clear();
		std::exit(EXIT_FAILURE);
	}

	while (std::getline(file, line)) {
		for (const char c : line) {
			if (c == ',') {								
				switch (std::stoi(num)) {
					case 395: // invisible blocks
						load_floor_block(i, j);						
						break;
					case 8: // grass type 1
						load_normal_sprite(i, j, 1, ASSETS_PATH "graphics/grass/grass_1.png");
						break;
					case 9: // grass type 1
						load_normal_sprite(i, j, 1, ASSETS_PATH "graphics/grass/grass_2.png");
						break;
					case 10: // grass type 1
						load_normal_sprite(i, j, 1, ASSETS_PATH "graphics/grass/grass_3.png");
						break;
					default:
						break;
				}
				j++;
				num.clear();
			}
			else {
				num += c;
			}
		}		
		j = 0;
		i++;
	}

	file.close();
}


ze::LevelScene::LevelScene() {		
	load_normal_sprite(0, 0, 0, ASSETS_PATH "graphics/tilemap/ground.png");
	load_player();	
	read_csv_file(ASSETS_PATH "map/map_FloorBlocks.csv");
	read_csv_file(ASSETS_PATH "map/map_Grass.csv");
	
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
