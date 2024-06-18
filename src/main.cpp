#include <raylib.h>
#include <memory>
#include "constants.h"
#include "scene.h"


int main(int argc, char const *argv[]) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(ZE_SCREEN_WIDTH, ZE_SCREEN_HEIGHT, ZE_WINDOW_TITLE);
    
    ze::SceneId scene_id = ze::TitleScreenId;
    bool should_change_scene = false;

    std::unique_ptr<ze::Scene> scene = std::make_unique<ze::TitleScreen>();
    ze::ChangeSceneRequest change_scene_request = [&scene_id, &should_change_scene](const ze::SceneId next_scene_id) {
        scene_id = next_scene_id;
        should_change_scene = true;
    };

    while (!WindowShouldClose()) {
        // UPDATE
        scene->update(change_scene_request);
        
        // DRAW
        BeginDrawing();
        ClearBackground(BLACK);
        scene->draw();
        EndDrawing();
        
        // CHANGE SCENE
        if (should_change_scene == true) {
            should_change_scene = false;
            switch (scene_id) {
                case ze::TitleScreenId:
                    scene = std::make_unique<ze::TitleScreen>();
                    break;
                case ze::LevelSceneId:
                    scene = std::make_unique<ze::LevelScene>();
                    break;
                default:
                    break;
            };
        }

    }

    scene.reset(nullptr);
    ze::gTexturePool.clear();
    CloseWindow();

    return 0;
}
