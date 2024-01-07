#include "../../include/scene/scene.hpp"




ze::Scene::Scene(
    const ze::SceneId& id,
    const ze::ChangeScene& changeScene
) : id(id),
    changeScene(changeScene) {

    }


ze::Scene::~Scene() {
    
}


void ze::Scene::update(const float& dt) {
    this->camera.update(dt);
}


void ze::Scene::draw(sf::RenderWindow& window) {
    this->camera.draw(window);
}