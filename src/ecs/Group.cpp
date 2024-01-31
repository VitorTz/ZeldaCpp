#include "../../include/ecs/Group.hpp"


void ze::Group::update(const float dt) {
    for (ze::GameObj* obj : allObjs) {
        obj->update(dt);
    }
}



void ze::Group::insert(ze::GameObj* gameObj) {    
    allObjs.insert(gameObj);
}


void ze::Group::erase(ze::GameObj* gameObj) {
    allObjs.erase(gameObj);
}


bool ze::Group::contains(ze::GameObj* gameObj) {
    return allObjs.find(gameObj) != allObjs.end();
}


std::set<ze::GameObj*>* ze::Group::getAllObjs() {
    return &allObjs;
}