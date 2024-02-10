#include "../../include/ecs/GameObj.hpp"


ze::GameObj::GameObj(
    std::string name_,
    const int zIndex_ = 0
) : name(std::move(name_)),
    zIndex(zIndex_) {

}



void ze::GameObj::update(const float dt) {
    for (const auto& [name, component] : componentMap) {
        component->update(dt);
    }
}


void ze::GameObj::draw(sf::RenderWindow& window) {
    for (const auto& [name, component] : componentMap) {
        component->draw(window);
    }
}



void ze::GameObj::addComponent(std::unique_ptr<ze::Component> c) {
    c->setGameObj(this);
    componentMap.insert({c->name, std::move(c)});
}


ze::Component* ze::GameObj::getComponent(const std::string& name) {
    return componentMap.at(name).get();
}