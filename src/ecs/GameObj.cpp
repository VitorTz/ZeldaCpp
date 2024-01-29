#include "../../include/ecs/ecs.hpp"



void ze::GameObj::update(const float dt) {
    for (const auto& [name, component] : this->componentMap) {
        component->update(dt);
    }
}


void ze::GameObj::draw(sf::RenderWindow& window) {
    for (const auto& [name, component] : this->componentMap) {
        component->draw(window);
    }
}


void ze::GameObj::addComponent(std::unique_ptr<ze::Component> c) {
    c->setGameObj(this);
    this->componentMap.insert({c->name, std::move(c)});
}

