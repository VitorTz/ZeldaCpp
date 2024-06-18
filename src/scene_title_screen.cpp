#include "scene.h"
#include <raylib.h>


ze::TitleScreen::TitleScreen(

) : logo(ze::gTexturePool.load(ASSETS_PATH "logo/logo.png")),
    background(ze::gTexturePool.load(ASSETS_PATH "logo/background.png")) {

}


void ze::TitleScreen::update(const ze::ChangeSceneRequest& change_scene_request) {
    
}


void ze::TitleScreen::draw() {
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(logo, ZE_SCREEN_WIDTH / 2 - logo.width / 2, ZE_SCREEN_HEIGHT / 2 - logo.height / 2, WHITE);
}