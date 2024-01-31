#include "../../include/ecs/GroupPool.hpp"


ze::GroupPool::GroupPool() {
    for (const ze::GroupId id : ze::allGroups) {
        this->groupMap.insert({id, std::make_unique<ze::Group>(id)});
    }
    this->groupMap.insert({ze::GroupId::CameraGroup, std::make_unique<ze::Camera>()});
}



void ze::GroupPool::addToGroup(ze::GameObj* gameObj, const ze::GroupId id) {
    if (groupsByGameObj.find(gameObj) == groupsByGameObj.end()) {
        groupsByGameObj.insert({gameObj, {}});
    }
    groupsByGameObj.at(gameObj).insert(id);
    groupMap.at(id)->insert(gameObj);    
}


void ze::GroupPool::rmvFromGroup(ze::GameObj* gameObj, const ze::GroupId id) {
    groupsByGameObj.at(gameObj).erase(id);
    groupMap.at(id)->erase(gameObj);
}


void ze::GroupPool::rmvFromAllGroups(ze::GameObj* gameObj) {
    std::set<ze::GroupId>* ids = &groupsByGameObj.at(gameObj);
    for (const ze::GroupId id : *ids) {
        groupMap.at(id)->erase(gameObj);        
    }
    ids->clear();
}


ze::Group* ze::GroupPool::get(const ze::GroupId id) {
    return this->groupMap.at(id).get();    
}