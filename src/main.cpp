#include <raylib.h>
#include <iostream>
#include "mrandom.hpp"
#include "constants.hpp"
#include "texture_pool.hpp"
#include "scene_manager.hpp"
#include "weapon.hpp"
#include "globals.hpp"


int main(int argc, char const *argv[]) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(ZE_SCREEN_W, ZE_SCREEN_H, ZE_WINDOW_TITLE);    

    Image icon = LoadImage("assets/icon/icon.png");
    SetWindowIcon(icon);

    ze::mrandom_init();    
    ze::globals::init();
    ze::weapon_load_textures();
    ze::gSceneManager.init();
    
    while (!WindowShouldClose()) {
        ze::gSceneManager.update();
        ze::gSceneManager.draw();    
    }
    
    UnloadImage(icon);
    ze::globals::close();
    ze::gTexturePool.clear();
    CloseWindow();

    return 0;
}
