#include <raylib.h>
#include <iostream>
#include "scene.hpp"
#include "scene_manager.hpp"
#include "texture_pool.hpp"
#include "tile_map.hpp"
#include "player.hpp"
#include "ecs.hpp"


ze::LevelScene::LevelScene() {
    ze::entity_t e{};
    ze::transform_t* t;

    // map ground
    e = ze::gEcs.entityCreate(0, true);
    ze::gEcs.insertComponent<ze::sprite_t>(e, ze::sprite_t{ze::gTexturePool.load("assets/graphics/tilemap/ground.png")});    

    // player
    ze::gPlayer.playerEntity = ze::gEcs.entityCreate(1, true);
    ze::gPlayer.playerWeaponEntity = ze::gEcs.entityCreate(2, true);
    ze::gEcs.insertComponent<ze::sprite_t>(ze::gPlayer.playerWeaponEntity, ze::sprite_t{});    
    ze::gEcs.insertComponent<ze::sprite_animation_t>(    
        ze::gPlayer.playerEntity, 
        ze::sprite_animation_t{
            ze::gTexturePool.load("assets/graphics/player/id.png"),
            ZE_TILE_SIZE,
            ZE_ANIMATION_SPEED_NORMAL
        }
    );
    ze::transform_t& playerTransform = ze::gEcs.getTransform(ze::gPlayer.playerEntity);
    playerTransform.size = {(float) ZE_TILE_SIZE, (float) ZE_TILE_SIZE};
    playerTransform.pos = ze::gPlayer.lastPos;
    playerTransform.speed = ZE_PLAYER_SPEED;

    // tiles
    std::vector<ze::tile_t> tiles; tiles.reserve(1024);
    ze::read_csv("assets/map/map_Grass.csv", &tiles, ze::Grass);
    ze::read_csv("assets/map/map_FloorBlocks.csv", &tiles, ze::Block);
    
    for (const ze::tile_t& tile : tiles) {
        switch (tile.type) {
            case ze::Grass:
                e = ze::gEcs.entityCreate(1, true);
                t = std::addressof(ze::gEcs.getTransform(e));
                t->pos = tile.pos;
                t->size = {ZE_TILE_SIZE, ZE_TILE_SIZE};
                ze::gEcs.insertComponent<ze::sprite_t>(e, ze::sprite_t{tile.texture});
                break;
            case ze::Block:
                e = ze::gEcs.entityCreate(0, false);
                t = std::addressof(ze::gEcs.getTransform(e));
                t->pos = tile.pos;
                t->size = {ZE_TILE_SIZE, ZE_TILE_SIZE};
                ze::gEcs.insertComponent<ze::obstacle_t>(e, ze::obstacle_t{.hitbox = {0.80f, 0.60f}});
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