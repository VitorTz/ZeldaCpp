#include "../../include/group/group.hpp"



og::Group::Group(
    const std::string& name
) : name(name) {

}


bool og::Group::contains(og::GameObj* obj) const {
    return this->objs.find(obj) != this->objs.end();
}


void og::Group::add(og::GameObj* obj) {
    this->objs.insert(obj);
}


void og::Group::rmv(og::GameObj* obj) {
    this->objs.erase(obj);
}


std::set<og::GameObj*>* og::Group::getObjs() {
    return &this->objs;
}