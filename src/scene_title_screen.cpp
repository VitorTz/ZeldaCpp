#include "scene_manager.hpp"
#include "constants.hpp"
#include "texture_pool.hpp"
#include "globals.hpp"


ze::TitleScreenScene::TitleScreenScene() {
    this->pos[0] = {0.0f, 0.0f};
    this->pos[1] = {ZE_SCREEN_WIDTH, 0.0f};
}


void ze::TitleScreenScene::update() {
    const float dt = GetFrameTime();
    for (int i = 0; i < 2; i++) {
        Vector2* v = &this->pos[i];
        v->x -= dt * 100.0f;
        if (v->x + ZE_SCREEN_WIDTH < 0) {
            v->x += ZE_SCREEN_WIDTH * 2;
        }
    }
    if (IsKeyPressed(KEY_SPACE)) {        
        ze::gSceneManager.changeScene(ze::LevelSceneId);
    }
}


void ze::TitleScreenScene::draw() {
    const Texture2D b1 = ze::gTexturePool.load("assets/logo/background.png");
    const Texture2D b2 = ze::gTexturePool.load("assets/logo/background1.png");
    const Texture2D logo = ze::gTexturePool.load("assets/logo/logo.png");    
    BeginDrawing();
    ClearBackground(BLACK);    
        DrawTextureV(b1, this->pos[0], WHITE);
        DrawTextureV(b2, this->pos[1], WHITE);
        DrawTextureV(logo, {ZE_SCREEN_WIDTH / 2.f - logo.width / 2.f, ZE_SCREEN_HEIGHT / 2.f - logo.height / 2.f}, WHITE);
        DrawTextEx(
            ze::globals::font, 
            "PRESS SPACE", 
            {ZE_SCREEN_WIDTH / 2.f - 120, ZE_SCREEN_HEIGHT - 220.0f},
            52,
            1.0f,
            BLACK
        );
    EndDrawing();
}