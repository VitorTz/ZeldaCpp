#include "../../include/ecs/ecs.hpp"


ze::GameObjPool::GameObjPool() {

}


ze::GameObjPool::~GameObjPool() {
    this->objMap.clear();
}


void ze::GameObjPool::update(const float dt) {
    for (const auto& [objName, obj] : this->objMap) {
        obj->update(dt);
    }
}


void ze::GameObjPool::createGroup(const std::string& groupName) {
    this->groupMap.insert({groupName, std::make_unique<ze::Group>()});
}


void ze::GameObjPool::createGroup(const std::string& groupName, std::unique_ptr<ze::Group> group) {
    this->groupMap.insert({groupName, std::move(group)});
}


void ze::GameObjPool::createGroups(const std::vector<std::string>& groups) {
    for (const std::string& groupName : groups) {
        this->groupMap.insert({groupName, std::make_unique<ze::Group>()});
    }
}

ze::Group* ze::GameObjPool::getGroup(const std::string& groupName) {
    return this->groupMap.at(groupName).get();
}


std::set<ze::Group*> ze::GameObjPool::getGroupsByName(
    const std::vector<std::string>& groups
) {
    std::set<ze::Group*> v;
    for (const std::string& groupName : groups) {
        v.insert(this->getGroup(groupName));
    }
    return v;       
}

ze::GameObj* ze::GameObjPool::createObj(
    const std::string& objName,
    const ze::Zindex index,
    const std::vector<std::string>& groups
) {
    ze::GameObj* obj;
    std::unique_ptr<ze::GameObj> gameObj = std::make_unique<ze::GameObj>(
        objName, 
        index, 
        this->getGroupsByName(groups)
    );
    obj = gameObj.get();
    this->objMap.insert({objName, std::move(gameObj)});
    return obj;
}


void ze::GameObjPool::deleteObj(ze::GameObj* obj) {
    this->objMap.erase(obj->name);
}


void ze::GameObjPool::deleteObj(const std::string& objName) {
    this->objMap.erase(objName);
}


ze::GameObj* ze::GameObjPool::getObj(const std::string& objName) {
    return this->objMap.at(objName).get();
}


const std::map<std::string, std::unique_ptr<ze::Group>>* ze::GameObjPool::getGroups() {
    return &this->groupMap;
}

std::size_t ze::GameObjPool::size() const {
    return this->objMap.size();
}