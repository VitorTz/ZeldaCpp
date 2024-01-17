#include "../../include/ecs/game_obj_pool.hpp"


og::GameObjPool::GameObjPool(

) {

}

void og::GameObjPool::update(const float dt) {
    for (const auto& [name, obj] : this->objs)
        obj->update(dt);
}


void og::GameObjPool::add(std::unique_ptr<og::GameObj>& obj) {
    this->objs.insert({obj->name, std::move(obj)});
}


void og::GameObjPool::rmv(const std::string& name) {
    this->objs.erase(name);
}


std::map<std::string, std::unique_ptr<og::GameObj>>* og::GameObjPool::getObjs() {
    return &this->objs;
}