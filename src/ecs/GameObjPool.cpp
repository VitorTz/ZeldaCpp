//
// Created by vitor on 1/28/24.
//
#include "../../include/ecs/ecs.h"


std::map<std::string, std::unique_ptr<ze::GameObj>> ze::GameObjPool::gameObjMap;


ze::GameObj* ze::GameObjPool::create(const std::string& name, const int zIndex, const std::vector<ze::GroupId>& ids) {
    const auto& [pair, success] = ze::GameObjPool::gameObjMap.insert(
        {name, std::make_unique<ze::GameObj>(name, zIndex)}
    );
    ze::GameObj* obj = pair->second.get();
    for (const ze::GroupId id : ids) {
        obj->addToGroup(ze::GroupPool::get(id));
    }
    return obj;
}


ze::GameObj* ze::GameObjPool::get(const std::string &name) {
    return ze::GameObjPool::gameObjMap.at(name).get();
}



void ze::GameObjPool::erase(const std::string &name) {
    ze::GameObjPool::gameObjMap.erase(name);
}


void ze::GameObjPool::clear() {
    ze::GameObjPool::gameObjMap.clear();
}