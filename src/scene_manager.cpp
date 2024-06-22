#include "scene_manager.hpp"
#include "constants.hpp"
#include "texture_pool.hpp"


ze::SceneManager::SceneManager(

) : nextScene(ze::TitleScreenSceneId) {
    this->loadNextScene();
}


void ze::SceneManager::loadNextScene() {
    ze::gTexturePool.clear();
    switch (this->nextScene) {
        case ze::TitleScreenSceneId:
            this->scene = std::make_unique<ze::TitleScreenScene>();
            break;
        case ze::LevelSceneId:
            this->scene = std::make_unique<ze::LevelScene>();
            break;
        default:
            break;
    }    
}

void ze::SceneManager::changeScene(const ze::SceneId sceneId) {
    this->shouldChangeScene = true;
    this->nextScene = sceneId;
}


void ze::SceneManager::update() {
    this->scene->update();    
}


void ze::SceneManager::draw() {
    this->scene->draw();
    if (this->shouldChangeScene == true) {
        this->shouldChangeScene = false;
        this->loadNextScene();
    }
}