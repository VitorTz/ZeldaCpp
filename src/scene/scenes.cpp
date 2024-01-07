#include "../../include/scene/scenes.hpp"


ze::Scene* ze::scene = nullptr;


ze::ChangeScene ze::changeScene = [](const ze::SceneId& id) {
    if (ze::scene == nullptr || ze::scene->id != id) {
        if (ze::scene) delete ze::scene;
        switch (id) {
            case ze::SceneId::LevelId:
                ze::scene = new ze::Level(ze::changeScene);                
                break;
            default:
                break;
        }
    }
};