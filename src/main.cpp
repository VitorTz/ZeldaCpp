#include <stdlib.h>
#include <raylib.h>
#include "globals.hpp"
#include "texture_pool.hpp"
#include "scene_manager.hpp"
#include "constants.hpp"
#include "ecs.hpp"


int main(int argc, char const *argv[]) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(ZE_SCREEN_WIDTH, ZE_SCREEN_HEIGHT, ZE_WINDOW_TITLE);
    ze::globals::init();    
    Image icon = LoadImage("assets/icon/icon.png");
    SetWindowIcon(icon);
    
    while (!WindowShouldClose()) {                
        ze::gSceneManager.update();
        ze::gSceneManager.draw();
    }
    
    ze::gTexturePool.clear();
    ze::globals::close();
    UnloadImage(icon);
    CloseWindow();
    return 0;
}
