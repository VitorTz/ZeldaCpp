#include "../../include/scene/Level.hpp"
#include <iostream>


ze::Level::Level(
    const ze::ChangeScene& changeScene
) : ze::Scene(ze::SceneId::LevelId, changeScene) {
    this->gameObjPool->groupPool->create(std::make_unique<ze::Camera>());
    
    // ground
    this->gameObjPool->create(
        "Ground", 
        -1, 
        {ze::GroupId::CameraGroup},
        std::make_unique<ze::Sprite>("res/graphics/tilemap/ground.png")
    );    

    // player
    this->gameObjPool->create(
        "Player",
        2,
        {ze::GroupId::CameraGroup},
        std::make_unique<ze::Player>()
    );

    // trees
    for (int i = 0; i < 25; i++) {
        const std::string name = "Tree-" + std::to_string(i);
        this->gameObjPool->create(
            name,
            2,
            {ze::GroupId::CameraGroup, ze::GroupId::CollideGroup},
            std::make_unique<ze::Sprite>("res/graphics/objects/01.png")
        );
        ze::GameObj* tree = this->gameObjPool->get(name);
        tree->rect.setPos(
            {
                static_cast<float>(ze::randomInt(0, ze::SCREEN_WIDTH)),
                static_cast<float>(ze::randomInt(0, ze::SCREEN_HEIGHT))
            }
        );
    }
    
}



void ze::Level::handleCollide() {
    ze::GameObj* player = this->gameObjPool->get("Player");
    if (this->gameObjPool->groupPool->collideGroup(player, ze::GroupId::CollideGroup)) {
        player->undoLastMovement();
    }
}


void ze::Level::update(float dt) {
    this->gameObjPool->groupPool->get(ze::GroupId::AllGroup)->update(dt);
    this->handleCollide();
}


void ze::Level::draw(sf::RenderWindow& window) {
    auto* camera = (ze::Camera*) this->gameObjPool->groupPool->get(ze::GroupId::CameraGroup);
    ze::GameObj* player = this->gameObjPool->get("Player");
    camera->draw(window, player->rect.center());
}