#include "../../include/scene/level.hpp"
#include <iostream>

ze::Level::Level(
    const ze::ChangeScene& changeScene 
) : ze::Scene(ze::SceneId::LevelId, changeScene),
    player(std::make_shared<ze::GameObj>("Player", ze::Zindex::PlayerIndex)) {
        
    this->addObj(player, {"camera", "all"});
    this->player->addComponent(new ze::Player());

    std::shared_ptr<ze::GameObj> ground = std::make_shared<ze::GameObj>("Ground", ze::Zindex::GroundIndex);
    ground->addComponent(new ze::Sprite({ze::GROUND_IMAGE_FILE}));
    this->addObj(ground, {"camera"});

    this->addGroup(new ze::Group("tress"));
    for (int i = 0; i < 25; i++) {
        float left = ze::randomInt(0, ze::SCREEN_WIDTH);
        float top = ze::randomInt(0, ze::SCREEN_HEIGHT);
        std::shared_ptr<ze::GameObj> treeObj = std::make_shared<ze::GameObj>("Tree-" + std::to_string(i), ze::Zindex::PlayerIndex);
        treeObj->transform.pos = {left, top};
        treeObj->addComponent(new ze::Tree());
        this->addObj(treeObj, {"all", "camera", "tress", "collide"});
    }   

}


void ze::Level::update(const float dt) {
    ze::Scene::update(dt);
    if (this->collideGroup->collide(this->player)) {
        ze::Player* pComponent = (ze::Player*) this->player->getComponent("Player");
        pComponent->undoMovement();
    }
}


void ze::Level::draw(sf::RenderWindow& window) {
    this->camera->draw(window, this->player->transform.center());
}