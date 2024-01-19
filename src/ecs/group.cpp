#include "../../include/ecs/ecs.hpp"



ze::Group::Group() { }


void ze::Group::add(ze::GameObj* obj) {
    this->objs.insert(obj);
}


void ze::Group::rmv(ze::GameObj* obj) {
    this->objs.erase(obj);
}


void ze::Group::clear() {
    this->objs.clear();
}

std::set<ze::GameObj*>* ze::Group::getObjs() {
    return &this->objs;
}


std::size_t ze::Group::size() const {
    return this->objs.size();
}