#include "../../include/scene/scene.hpp"


ze::Scene::Scene(
    const ze::SceneId id,
    const ze::ChangeScene& changeScene
) : id(id),
    changeScene(changeScene),
    gameObjPool(std::make_unique<ze::GameObjPool>()) {
        this->gameObjPool->createGroup("camera", std::make_unique<ze::Camera>());
    }


ze::Scene::~Scene() = default;


void ze::Scene::update(const float dt) {
    this->gameObjPool->update(dt);
}


void ze::Scene::draw(sf::RenderWindow& window) {
    ze::Camera* camera = (ze::Camera*) this->gameObjPool->getGroup("camera");
    camera->draw(window);
    ze::debug(window, this->gameObjPool);
}