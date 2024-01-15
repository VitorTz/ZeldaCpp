#include "../../../include/util/group/game_obj_group.hpp"



ze::GameObjGroup::GameObjGroup(
    const std::string& name 
) : ze::Group(name) {

}


void ze::GameObjGroup::add(const std::shared_ptr<ze::GameObj>& obj) {
    this->objs.insert({obj->name, obj});
}


void ze::GameObjGroup::rmv(const std::string& name) {
    this->objs.erase(name);
}


ze::GameObj* ze::GameObjGroup::get(const std::string& name) {
    try {
        return this->objs.at(name).get();
    } catch (std::out_of_range& e) {
        
    }
    return nullptr;
}


void ze::GameObjGroup::update(const float dt) {
    for (const auto& [name, obj] : this->objs) 
        obj->update(dt);
}


void ze::GameObjGroup::draw(sf::RenderWindow& window) {
    for (const auto& [name, obj] : this->objs) 
        obj->draw(window);
}