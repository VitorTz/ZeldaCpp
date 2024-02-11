#include "../../include/ecs/Ecs.hpp"


ze::GroupPool::GroupPool() {
    for (const ze::GroupId id : ze::groupsIds) {
        groupMap.insert({id, std::make_unique<ze::Group>(id)});
    }
    groupMap.insert({ze::GroupId::CameraGroup, std::make_unique<ze::Camera>()});
}



void ze::GroupPool::addToGroup(ze::GameObj* gameObj, const ze::GroupId id) {
    groupMap.at(id)->insert(gameObj);
    if (groupByGameObj.find(gameObj) == groupByGameObj.end()) {
        groupByGameObj.insert({gameObj, {}});
    }
    groupByGameObj.at(gameObj).insert(id);
}


void ze::GroupPool::rmvFromGroup(ze::GameObj* gameObj, const ze::GroupId id) {
    groupMap.at(id)->erase(gameObj);
    groupByGameObj.at(gameObj).erase(id);
}


void ze::GroupPool::rmvGameObj(ze::GameObj* gameObj) {
    groupByGameObj.erase(gameObj);
}


ze::Group* ze::GroupPool::at(ze::GroupId id) {
    return groupMap.at(id).get();
}


std::set<ze::GroupId>* ze::GroupPool::getGroupsByGameObj(ze::GameObj* gameObj) {
    return &groupByGameObj.at(gameObj);
}


bool ze::GroupPool::collideGroup(ze::GameObj* gameObj, const ze::GroupId id) {
    for (ze::GameObj* other : *groupMap.at(id)->getAll()) {
        if (gameObj->transform.collideWithShrink(other->transform)) {
            return true;
        }
    }     
    return false;
}


ze::GameObj* ze::GameObjPool::insert(
    const std::string& name,
    const int zIndex,
    ze::GroupPool* groupPool,
    const std::vector<ze::GroupId>& groups = std::vector<ze::GroupId>()
) {
    const auto& [pair, success] = allObjs.insert(
        {name, std::make_unique<ze::GameObj>(name, zIndex)}
    );
    ze::GameObj* gameObj = pair->second.get();
    for (const ze::GroupId id : groups) {
        groupPool->addToGroup(gameObj, id);
    }
    return gameObj;
}


ze::GameObj* ze::GameObjPool::at(const std::string& name) {
    return allObjs.at(name).get();
}


void ze::GameObjPool::erase(ze::GameObj* gameObj, ze::GroupPool* groupPool) {
    for (const ze::GroupId id : *groupPool->getGroupsByGameObj(gameObj)) {
        groupPool->at(id)->erase(gameObj);        
    }
    groupPool->rmvGameObj(gameObj);
    allObjs.erase(gameObj->name);
}


void ze::GameObjPool::erase(const std::string& name, ze::GroupPool* groupPool) {
    erase(allObjs.at(name).get(), groupPool);
}


std::size_t ze::GameObjPool::size() const {
    return allObjs.size();
}


void ze::GameObjPool::update(const float dt) {
    for (const auto& [name, gameObj] : allObjs) {
        gameObj->update(dt);
    }
}


std::unique_ptr<ze::GroupPool> ze::Ecs::groupPool = std::make_unique<ze::GroupPool>();

std::unique_ptr<ze::GameObjPool> ze::Ecs::gameObjPool = std::make_unique<ze::GameObjPool>();

