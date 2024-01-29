#include "../../include/ecs/GroupPool.hpp"




void ze::GroupPool::addToGroup(
    ze::GameObj* obj,
    const ze::GroupId id
) {
    if (this->groupsByGameObj.find(obj) == this->groupsByGameObj.end()) {
        this->groupsByGameObj.insert({obj, {}});
    }
    this->groupMap.at(id)->add(obj);
    this->groupsByGameObj.at(obj).insert(id);
}


void ze::GroupPool::addToGroup(
    ze::GameObj* obj, 
    const std::vector<ze::GroupId>& ids
) {
    for (const ze::GroupId id : ids) {
        this->addToGroup(obj, id);
    }
}


void ze::GroupPool::rmvFromGroup(ze::GameObj* obj, const ze::GroupId id) {
    this->groupsByGameObj.at(obj).erase(id);
    this->groupMap.at(id)->erase(obj);
}


void ze::GroupPool::rmvFromAllGroups(ze::GameObj* gameObj) {
    std::set<ze::GroupId>* ids = &this->groupsByGameObj.at(gameObj);
    while (!ids->empty()) {
        this->rmvFromGroup(
            gameObj,
            ids->extract(ids->begin()).value()
        );
    }
}



bool ze::GroupPool::collideGroup(ze::GameObj* obj, const ze::GroupId id) {
    const ze::Rect r1 = obj->rect.shrink(obj->boxCollideScale);
    const std::set<ze::GameObj*>* objs = this->groupMap.at(id)->getAll();
    return std::any_of(
        objs->begin(), objs->end(),
        [&r1](const ze::GameObj* otherObj) {
            return ze::Rect::collide(r1, otherObj->rect.shrink(otherObj->boxCollideScale));
        }
    );
}

