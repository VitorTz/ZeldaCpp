#include <raylib.h>
#include "scene.hpp"
#include "constants.hpp"
#include "texture_pool.hpp"
#include "scene_manager.hpp"
#include "globals.hpp"


Vector2 backgroundPos[2];


ze::TitleScreen::TitleScreen() {
    for (int i = 0; i < 2; i++) {
        backgroundPos[0] = {static_cast<float>(ZE_SCREEN_W * i), 0.0f};
    }
}


void ze::TitleScreen::update() {
    const float dt = GetFrameTime();
    for (int i = 0; i < 2; i++) {
        Vector2* v = &backgroundPos[i];
        v->x -= dt * 100.0f;
        if (v->x + ZE_SCREEN_W < 0.0f) {
            v->x += ZE_SCREEN_W * 2.0f;
        }
        
    }
    if (IsKeyPressed(KEY_SPACE)) {        
        ze::gSceneManager.requestChangeScene(ze::LevelSceneId);
    }
}


void ze::TitleScreen::draw() {
    Texture2D logo = ze::gTexturePool.load("assets/logo/logo.png");
    BeginDrawing();
    ClearBackground(BLACK);
        DrawTextureV(ze::gTexturePool.load("assets/logo/background.png"), backgroundPos[0], WHITE);
        DrawTextureV(ze::gTexturePool.load("assets/logo/background1.png"), backgroundPos[1], WHITE);
        DrawTextureV(
            logo, 
            {ZE_SCREEN_CENTERX - logo.width / 2.0f, ZE_SCREEN_CENTERY - logo.height / 2.0f}, 
            WHITE
        );
        DrawTextEx(
            ze::globals::font,
            "PRESS SPACE",
            {ZE_SCREEN_CENTERX - 120.0f, ZE_SCREEN_H - 220.0f},
            52,
            1.0f,
            BLACK
        );
        
    EndDrawing();
}