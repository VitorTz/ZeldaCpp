//
// Created by vitor on 1/28/24.
//
#include "../../include/ecs/ecs.h"


std::map<ze::GroupId, std::unique_ptr<ze::Group>> ze::GroupPool::groupMap;


void ze::GroupPool::create(ze::GroupId id) {
    ze::GroupPool::groupMap.insert({id, std::make_unique<ze::Group>(id)});
}


void ze::GroupPool::create(std::unique_ptr<ze::Group> group) {
    ze::GroupPool::groupMap.insert({group->id, std::move(group)});
}


void ze::GroupPool::create(const std::vector<ze::GroupId>& groups) {
    for (const ze::GroupId id : groups) {
        ze::GroupPool::groupMap.insert({id, std::make_unique<ze::Group>(id)});
    }
}


ze::Group* ze::GroupPool::get(ze::GroupId id) {
    return ze::GroupPool::groupMap.at(id).get();
}


void ze::GroupPool::clear() {
    ze::GroupPool::groupMap.clear();
}