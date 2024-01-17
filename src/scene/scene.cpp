#include "../../include/scene/scene.hpp"


og::Scene::Scene(
    const og::SceneId id,
    const og::ChangeScene& changeScene
) : id(id),
    changeScene(changeScene),
    allObjs(std::make_unique<og::GameObjPool>()) {
        this->addGroup(std::make_unique<og::Group>("collide"));
        this->addGroup(std::make_unique<og::Camera>());        
        this->collideGroup = (og::Group*) this->getGroup("collide");
        this->cameraGroup = (og::Camera*) this->getGroup("camera");
    }


og::Scene::~Scene() = default;


void og::Scene::addGroup(std::unique_ptr<og::Group> group) {
    this->groups.insert({group->name, std::move(group)});
}

og::Group* og::Scene::getGroup(const std::string& gName) {
    return this->groups.at(gName).get();
}


void og::Scene::addObjToGroups(
    std::unique_ptr<og::GameObj>& obj,
    const std::vector<std::string>& groups
) {
    for (const std::string& groupName : groups) {
        this->groups.at(groupName)->add(obj.get());
        obj->addGroup(groupName);
    }
    this->allObjs->add(obj);
}


void og::Scene::rmvObjFromGroups(og::GameObj* obj) {
    for (const std::string& groupName : obj->getGroups()) {
        this->groups.at(groupName)->rmv(obj);
    }
    this->allObjs->rmv(obj->name);
}


void og::Scene::rmvAllObjsFromGroup(const std::string& groupName) {
    std::unique_ptr<og::Group>& group = this->groups.at(groupName);
    std::set<og::GameObj*>* objs = group->getObjs();
    while (!objs->empty()) {
        auto i = objs->extract(objs->begin());
        this->rmvObjFromGroups(i.value());
    }
}


void og::Scene::update(const float dt) {
    this->allObjs->update(dt);
}


void og::Scene::draw(sf::RenderWindow& window) {
    this->cameraGroup->draw(window);
}