#include "scene_manager.hpp"
#include "constants.hpp"
#include "ecs.hpp"
#include "globals.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <random>


static void create_player(const float posX, const float posY, const ze::zindex_t z_index) {
    const ze::entity_t player = ze::gEcs.entityCreate(z_index, true);
    ze::globals::playerEntity = player;
    ze::gEcs.addComponent<ze::controller_t>(player, ze::controller_t{}, ze::ControllerId);    
    ze::gEcs.addComponent<ze::player_t>(player, ze::player_t{}, ze::PlayerId);
    ze::gEcs.getComponent<ze::player_t>(player, ze::PlayerId).animation.changeTexture("assets/graphics/player/id.png");    
    ze::gEcs.addComponent<ze::obstacle_t>(player, ze::obstacle_t{{0.80f, 0.60f}}, ze::ObstacleId);    
    ze::transform_t& t = ze::gEcs.getTransform(player);
    t.rect.x = posX;
    t.rect.y = posY;
    t.rect.width = (float) ZE_TILE_SIZE;
    t.rect.height = (float) ZE_TILE_SIZE;
    t.speed = ZE_PLAYER_SPEED;
}


static void create_map_ground() {
    const ze::entity_t e = ze::gEcs.entityCreate(0, true);
    ze::gEcs.addComponent<ze::sprite_t>(e, ze::sprite_t{"assets/graphics/tilemap/ground.png"}, ze::SpriteId);
}


static void load_normal_sprite(
    const int posX,
    const int posY,
    const ze::zindex_t z_index,
    const char* file_name
) {
    const ze::entity_t e = ze::gEcs.entityCreate(z_index, true);
    ze::gEcs.addComponent<ze::sprite_t>(e, ze::sprite_t{file_name}, ze::SpriteId);
    ze::transform_t& t = ze::gEcs.getTransform(e);
    t.rect.x = static_cast<float>(posY * ZE_TILE_SIZE);
    t.rect.y = static_cast<float>(posX * ZE_TILE_SIZE);
    t.rect.width =  static_cast<float>(ZE_TILE_SIZE);
    t.rect.height = static_cast<float>(ZE_TILE_SIZE);
}


static void create_tiles(
    const char* csv,
    const ze::TileType tile_type,
    const ze::zindex_t z_index,
    const bool onCamera,
    std::vector<ze::tile_t>* tiles
) {
    std::ifstream f(csv, std::fstream::in);
    if (f.is_open() == false) {
        std::cout << "[ERRO AO ABRIR ARQUIVO CSV " << csv << "]\n";
        ze::gTexturePool.clear();
        ze::globals::close();
        std::exit(EXIT_FAILURE);        
    }

    std::string line, num;
    int i = 0, j = 0;
    while (std::getline(f, line)) {
        for (const char c : line) {
            if (c != ',') {
                num += c;
                continue;
            }
            int n = std::stoi(num);
            if (n != -1) {
                const ze::entity_t e = ze::gEcs.entityCreate(z_index, onCamera);
                ze::transform_t& t = ze::gEcs.getTransform(e);
                t.rect.x = static_cast<float>(j * ZE_TILE_SIZE);
                t.rect.y = static_cast<float>(i * ZE_TILE_SIZE);
                t.rect.width = static_cast<float>(ZE_TILE_SIZE);
                t.rect.height = static_cast<float>(ZE_TILE_SIZE);
                tiles->push_back(
                    ze::tile_t{
                        e,
                        n,
                        tile_type
                    }
                );                        
            }
            num.clear();
            j++;
        }
        j = 0;
        i++;
    }

    f.close();
}


ze::LevelScene::LevelScene() {    
    create_map_ground();
    create_player(2000.0f, 1430.0f, 1);

    std::vector<ze::tile_t> tiles;
    
    create_tiles(
        "assets/map/map_Grass.csv",
        ze::TileType::Grass,
        1,
        true,
        &tiles
    );

    create_tiles(
        "assets/map/map_FloorBlocks.csv",
        ze::TileType::Block,
        0,
        false,
        &tiles
    );

    std::vector<std::string> grass = ze::getFilesFromDir("assets/graphics/grass", ".png");
    std::uniform_int_distribution<int> randGrass(0, grass.size() - 1);

    for (const ze::tile_t& tile : tiles) {
        switch (tile.type) {
            case ze::Grass:
                ze::gEcs.addComponent<ze::sprite_t>(
                    tile.entity, 
                    ze::sprite_t{grass[randGrass(ze::globals::generator)].c_str()}, 
                    ze::SpriteId
                );
                break;
            case ze::Block:
                ze::gEcs.addComponent<ze::obstacle_t>(tile.entity, ze::obstacle_t{{0.80f, 0.90f}}, ze::ObstacleId);
                break;
            default:
                break;
        }
    }   
}


void ze::LevelScene::update() {
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