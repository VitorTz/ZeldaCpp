#include "../../../include/util/group/group.hpp"
#include <iostream>

ze::Group::Group(
    const std::string& name
) : name(name) {
    
}


ze::Group::~Group() = default;


void ze::Group::add(const std::shared_ptr<ze::GameObj>& obj) {
    this->objs.insert(obj);
}


void ze::Group::rmv(const std::shared_ptr<ze::GameObj>& obj) {
    this->objs.erase(obj);
    std::cout << "rmv from " << this->name << '\n';
}


bool ze::Group::contains(const std::shared_ptr<ze::GameObj>& obj) const {
    return this->objs.find(obj) != this->objs.end();
}


void ze::Group::update(const float dt) {
    for (const std::shared_ptr<ze::GameObj>& obj : this->objs)    
        obj->update(dt);
}


bool ze::Group::collide(const std::shared_ptr<ze::GameObj>& obj) const {
    for (const std::shared_ptr<ze::GameObj>& other_obj : this->objs) {
        if (obj->transform.collide(other_obj->transform)) {
            return true;
        }
    }
    return false;
}

std::set<std::shared_ptr<ze::GameObj>>& ze::Group::getObjs() {
    return this->objs;
}