#include "../../include/scene/scene.hpp"


ze::Scene::Scene(
    const ze::SceneId& id,
    const ze::ChangeScene& changeScene
) : id(id),
    changeScene(changeScene) {

    }


ze::Scene::~Scene() = default;



void ze::Scene::addGameObj(std::unique_ptr<ze::GameObj>& gameObj) {
    if (this->gameObjMap.find(gameObj->name) == this->gameObjMap.end()) {
        this->gameObjMap.insert(
            {gameObj->name, std::move(gameObj)}
        );
    }
}



ze::GameObj* ze::Scene::getGameObj(const std::string& n) {
    std::unique_ptr<ze::GameObj>& g = this->gameObjMap.at(n);
    return g.get();
}


void ze::Scene::rmvGameObj(const std::string& n) {
    this->gameObjMap.erase(n);
}


void ze::Scene::update(const float& dt) {
    for (const auto& [name, gameObj] : this->gameObjMap)
        gameObj->update(dt);
}


void ze::Scene::draw(sf::RenderWindow& window) {
    for (const auto& [name, gameObj] : this->gameObjMap)
        gameObj->draw(window);
}