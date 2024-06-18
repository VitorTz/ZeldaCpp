#include "scene.h"
#include <iostream>


ze::LevelScene::LevelScene() {

}


void ze::LevelScene::update(
    const ze::ChangeSceneRequest& change_scene_request
) {
    std::cout << "level update\n";
}


void ze::LevelScene::draw() {
    std::cout << "level draw\n";
}