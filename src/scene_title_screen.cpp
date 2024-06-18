#include "scene.h"
#include <raylib.h>


ze::TitleScreen::TitleScreen(

) : logo(ze::gTexturePool.load(ASSETS_PATH "logo/logo.png")) {
    backgroundSprite[0] = ze::gTexturePool.load(ASSETS_PATH "logo/background.png");
    backgroundSprite[1] = ze::gTexturePool.load(ASSETS_PATH "logo/background1.png");
    backgroundPos[0] = {0.0f, 0.0f};
    backgroundPos[1] = {(float) backgroundSprite[0].width, 0.0f};
}


void ze::TitleScreen::update(const ze::ChangeSceneRequest& change_scene_request) {
    const float dt = GetFrameTime();
    for (int i = 0; i < 2; i++) {
        Vector2* v = &backgroundPos[i];
        v->x -= dt * 100.0f;
        if (v->x + backgroundSprite[0].width < 0) {
            v->x += backgroundSprite[0].width * 2;
        }
    }
    if (IsKeyPressed(KEY_SPACE)) {
        ze::gTexturePool.erase(ASSETS_PATH "logo/background.png");
        ze::gTexturePool.erase(ASSETS_PATH "logo/background1.png");
        change_scene_request(ze::LevelSceneId);
    }
}


void ze::TitleScreen::draw() {
    for (int i = 0; i < 2; i++) {
        DrawTextureV(backgroundSprite[i], backgroundPos[i], WHITE);
    } 
    DrawTexture(
        logo, 
        ZE_SCREEN_WIDTH / 2 - logo.width / 2, 
        ZE_SCREEN_HEIGHT / 2 - logo.height / 2, 
        WHITE
    );
    const char text[] = "Press space";
    const Font font = ze::globals::get_font();    
    const Vector2 text_size = MeasureTextEx(font, text, 52, 1.0f);
    DrawTextEx(
        font, 
        text, 
        {ZE_SCREEN_WIDTH / 2 - text_size.x / 2, ZE_SCREEN_HEIGHT - 200},
        52,
        1.0f,
        BLACK
    );
}