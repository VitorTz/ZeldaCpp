#include "../../include/ecs/GameObjPool.hpp"



ze::GameObjPool::~GameObjPool() = default;



void ze::GameObjPool::create(
    const std::string& name, 
    int zIndex,
    const std::vector<ze::GroupId>& groups
) {
    std::unique_ptr<ze::GameObj> obj = std::make_unique<ze::GameObj>(name, zIndex);
    this->groupPool->addToGroup(obj.get(), groups);
    this->groupPool->addToGroup(obj.get(), ze::GroupId::AllGroup);
    this->objMap.insert({name, std::move(obj)});
}


void ze::GameObjPool::create(
    const std::string& name, 
    int zIndex,
    const std::vector<ze::GroupId>& groups,
    std::unique_ptr<ze::Component> component    
) {
    std::unique_ptr<ze::GameObj> obj = std::make_unique<ze::GameObj>(name, zIndex);
    this->groupPool->addToGroup(obj.get(), groups);
    obj.get()->addComponent(std::move(component));
    this->groupPool->addToGroup(obj.get(), ze::GroupId::AllGroup);
    this->objMap.insert({name, std::move(obj)});
}



ze::GameObj* ze::GameObjPool::get(const std::string& name) {
    return this->objMap.at(name).get();
}


void ze::GameObjPool::erase(const std::string& name) {
    this->groupPool->rmvFromAllGroups(this->objMap.at(name).get());
    this->objMap.erase(name);
}


void ze::GameObjPool::erase(ze::GameObj* obj) {
    this->groupPool->rmvFromAllGroups(obj);
    this->objMap.erase(obj->name);
}