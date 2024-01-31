#include "../../include/ecs/GameObjPool.hpp"


ze::GameObjPool::~GameObjPool() {
    this->gameObjMap.clear();    
}


void ze::GameObjPool::create(
    const std::string& name, 
    ze::Zindex zIndex,
    const std::vector<ze::GroupId>& groups   
) {
    std::unique_ptr<ze::GameObj> obj = std::make_unique<ze::GameObj>(name, zIndex);
    ze::GameObj* objPtr = obj.get();
    for (const ze::GroupId id : groups) {
        this->groupPool.addToGroup(objPtr, id);
    }
    this->gameObjMap.insert({name, std::move(obj)});
}


void ze::GameObjPool::create(
    const std::string& name, 
    ze::Zindex zIndex,
    const std::vector<ze::GroupId>& groups,
    std::unique_ptr<ze::Component> component
) {
    std::unique_ptr<ze::GameObj> obj = std::make_unique<ze::GameObj>(name, zIndex);
    ze::GameObj* objPtr = obj.get();
    objPtr->addComponent(std::move(component));
    for (const ze::GroupId id : groups) {
        this->groupPool.addToGroup(objPtr, id);
    }
    this->gameObjMap.insert({name, std::move(obj)});
}


ze::GameObj* ze::GameObjPool::get(const std::string& name) {
    return this->gameObjMap.at(name).get();
} 



void ze::GameObjPool::erase(const std::string& name) {
    this->groupPool.rmvFromAllGroups(this->get(name));
    this->gameObjMap.erase(name);
}


void ze::GameObjPool::erase(ze::GameObj* gameObj) {
    this->groupPool.rmvFromAllGroups(gameObj);
    this->gameObjMap.erase(gameObj->name);
}


ze::Group* ze::GameObjPool::getGroup(const ze::GroupId id) {
    return this->groupPool.get(id);
}