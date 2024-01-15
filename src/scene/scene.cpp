#include "../../include/scene/scene.hpp"


ze::Scene::Scene(
    const ze::SceneId id,
    const ze::ChangeScene& changeScene
) : id(id),
    changeScene(changeScene) {
        this->groups.insert(
            {"camera", std::make_unique<ze::Camera>()}
        );
        this->groups.insert(
            {"all", std::make_unique<ze::GameObjGroup>("all")}
        );
    }


ze::Scene::~Scene() = default;


void ze::Scene::update(const float dt) {
    this->groups.at("camera")->update(dt);
}


void ze::Scene::draw(sf::RenderWindow& window) {
    this->groups.at("camera")->draw(window);
}


void ze::Scene::addToGroup(const std::shared_ptr<ze::GameObj>& obj, const std::vector<std::string>& groups) {
    for (const std::string& name : groups) {
        this->groups.at(name)->add(obj);
    }
}