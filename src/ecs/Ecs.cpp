#include "../../include/ecs/Ecs.hpp"


std::map<ze::GroupId, std::unique_ptr<ze::Group>> ze::Ecs::groupMap;
std::map<std::string, std::unique_ptr<ze::GameObj>> ze::Ecs::allObjs;
std::map<ze::GameObj*, std::set<ze::GroupId>> ze::Ecs::groupByGameObj;


void ze::Ecs::init() {
    for (const ze::GroupId id : ze::groupsIds) {
        ze::Ecs::groupMap.insert({id, std::make_unique<ze::Group>(id)});
    }
}


void ze::Ecs::createGroup(const ze::GroupId id) {
    ze::Ecs::groupMap.insert({id, std::make_unique<ze::Group>(id)});
}

void ze::Ecs::createGroup(std::unique_ptr<ze::Group> group) {
    ze::Ecs::groupMap.insert({group->id, std::move(group)});
}


ze::Group* ze::Ecs::getGroup(const ze::GroupId id) {
    return ze::Ecs::groupMap.at(id).get();
}


void ze::Ecs::createGameObj(
    const std::string& name, 
    int zIndex,
    const std::vector<ze::GroupId>& groups
) {
    const auto& [pair, success] = ze::Ecs::allObjs.insert(
        {name, std::make_unique<ze::GameObj>(name, zIndex)}
    );
    ze::GameObj* gameObj = pair->second.get();
    
    ze::Ecs::groupByGameObj.insert({gameObj, {}});
    for (const ze::GroupId id : groups) {
        ze::Ecs::groupByGameObj.at(gameObj).insert(id);
        ze::Ecs::getGroup(id)->insert(gameObj);
    }
}


ze::GameObj* ze::Ecs::getGameObj(const std::string& name) {
    return ze::Ecs::allObjs.at(name).get();
}


void ze::Ecs::deleteGameObj(ze::GameObj* gameObj) {
    for (const ze::GroupId id : ze::Ecs::groupByGameObj.at(gameObj)) {
        ze::Ecs::groupMap.at(id)->erase(gameObj);
    }
    ze::Ecs::groupByGameObj.erase(gameObj);
    ze::Ecs::allObjs.erase(gameObj->name);
}


bool ze::Ecs::collideGroup(ze::GameObj* gameObj, const ze::GroupId id) {
    for (ze::GameObj* other : *ze::Ecs::groupMap.at(id)->getAll()) {
        if (gameObj->transform.collideWithShrink(other->transform)) {
            return true;
        }
    }
    return false;
}


void ze::Ecs::rmvFromGroup(ze::GameObj* gameObj, const ze::GroupId id) {
    ze::Ecs::groupByGameObj.at(gameObj).erase(id);
    ze::Ecs::groupMap.at(id)->erase(gameObj);
}


void ze::Ecs::addToGroup(ze::GameObj* gameObj, const ze::GroupId id) {
    ze::Ecs::groupByGameObj.at(gameObj).insert(id);
    ze::Ecs::groupMap.at(id)->insert(gameObj);
}