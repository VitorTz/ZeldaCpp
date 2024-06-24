#include "scene_manager.hpp"


void ze::SceneManager::init() {
    this->scene = std::make_unique<ze::TitleScreen>();
}


void ze::SceneManager::requestChangeScene(const ze::SceneId sceneId) {
    this->should_change_scene = true;
    this->next_scene = sceneId;
}



void ze::SceneManager::update() {
    this->scene->update();
}


void ze::SceneManager::draw() {
    this->scene->draw();
    if (this->should_change_scene) {
        this->should_change_scene = false;
        switch (this->next_scene) {
            case ze::TitleScreenId:
                this->scene = std::make_unique<ze::TitleScreen>();
                break;
            case ze::LevelSceneId:
                this->scene = std::make_unique<ze::LevelScene>();
                break;
            default:
                break;
        }
    }
}