#include "../../include/ecs/GameObj.hpp"


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


void ze::GameObj::move(const float dt) {
    ze::normalizeVector(this->direction);
    this->lastMovement = {
        this->speed * dt * this->direction.x,
        this->speed * dt * this->direction.y
    };
    this->rect.pos += this->lastMovement;
}


void ze::GameObj::undoLastMovement() {
    this->rect.pos -= this->lastMovement;
    this->lastMovement = {0.f, 0.f};
}