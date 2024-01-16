#include "../../include/scene/scene.hpp"


ze::Scene::Scene(
    const ze::SceneId id,
    const ze::ChangeScene& changeScene
) : id(id),
    changeScene(changeScene),
    camera(new ze::Camera()),
    allObjsGroup(new ze::Group("all")),
    collideGroup(new ze::Group("collide")) {
        this->addGroup(this->camera);
        this->addGroup(this->allObjsGroup);
        this->addGroup(this->collideGroup);
    }


ze::Scene::~Scene() = default;


void ze::Scene::update(const float dt) {
    this->allObjsGroup->update(dt);
}


void ze::Scene::draw(sf::RenderWindow& window) {
    this->camera->draw(window);
}

void ze::Scene::addGroup(ze::Group* group) {
    this->groups.insert({group->name, std::unique_ptr<ze::Group>(group)});
}

void ze::Scene::addObj(const std::shared_ptr<ze::GameObj>& obj, const std::vector<std::string>& groups) {
    for (const std::string& name : groups) {
        this->groups.at(name)->add(obj);
        obj->addGroup(name);
    }
}

void ze::Scene::rmvAllFromGroup(const std::string& name) {
    std::set<std::shared_ptr<ze::GameObj>>& objs = this->groups.at(name)->getObjs();
    while (!objs.empty()) {
        auto i = objs.extract(objs.begin());
        std::shared_ptr<ze::GameObj>& obj = i.value();
        this->rmvObj(obj);
    }
}

void ze::Scene::rmvObj(const std::shared_ptr<ze::GameObj>& obj) {
    for (const std::string& name : obj->getGroups()) {
        this->groups.at(name)->rmv(obj);
    }
}