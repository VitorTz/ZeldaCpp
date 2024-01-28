//
// Created by vitor on 1/28/24.
//
#include "../../include/ecs/ecs.h"


void ze::Group::update(const float dt) {
    for (ze::GameObj* gameObj : this->allObjs) {
        gameObj->update(dt);
    }
}


void ze::Group::add(ze::GameObj *gameObj) {
    this->allObjs.insert(gameObj);
}


void ze::Group::rmv(ze::GameObj *gameObj) {
    gameObj->rmvFromGroup(this);
    this->allObjs.erase(gameObj);
}


void ze::Group::rmvAll() {
    while (!this->allObjs.empty()) {
        this->allObjs.extract(this->allObjs.begin()).value()->rmvFromGroup(this);
    }
}


std::set<ze::GameObj*>* ze::Group::getAllObjs() {
    return &this->allObjs;
}