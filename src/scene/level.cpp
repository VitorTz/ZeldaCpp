#include "../../include/scene/level.hpp"


ze::Level::Level(
    const ze::ChangeScene& changeScene
) : ze::Scene(ze::SceneId::LevelId, changeScene) {
    this->gameObjPool->createGroups({"collide", "trees"});
    ze::GameObj* ground = this->gameObjPool->createObj("ground", ze::Zindex::GroundIndex, {"camera"});
    ground->addComponent(std::make_unique<ze::Sprite>("res/graphics/tilemap/ground.png"));

    const ze::MapObj& mapObj = ze::mapObjById.at(ze::MapObjId::Tree2);
    for (int i = 0; i < 25; i++) {
        ze::GameObj* tree = this->gameObjPool->createObj(
            mapObj.name + '-' + std::to_string(i),
            mapObj.zIndex,
            mapObj.groups
        );
        tree->addComponent(std::make_unique<ze::Sprite>(mapObj));
        tree->transform.pos = {
            (float) ze::randomInt(0, ze::SCREEN_WIDTH),
            (float) ze::randomInt(0, ze::SCREEN_HEIGHT)
        };
    }
}


void ze::Level::handlePlayerCollide() {
    
}


void ze::Level::update(const float dt) {
    ze::Scene::update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->gameObjPool->deleteObj("ground");
    }
}


void ze::Level::draw(sf::RenderWindow& window) {
    ze::Scene::draw(window);
}