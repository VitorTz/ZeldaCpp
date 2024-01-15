#include "../../include/ecs/ecs.hpp"


ze::Component::Component(
    const std::string& name
) : name(name) {
    
}


ze::Component::~Component() = default;


void ze::Component::update([[maybe_unused]] const float dt) {

}


void ze::Component::draw([[maybe_unused]] sf::RenderWindow& window) {

}


void ze::Component::setGameObj(ze::GameObj* gameObj) {
    this->gameObj = gameObj;
}


ze::GameObj::GameObj(
    const std::string& name,
    const ze::Zindex zIndex
) : ze::GameObj(name, ze::Transform(zIndex)) {
    
}   


ze::GameObj::GameObj(
    const std::string& name,
    const ze::Transform& transform
) : name(name),
    transform(transform),
    state({ }),
    stats({ }) {
        
    }


void ze::GameObj::addComponent(ze::Component* c) {
    if (this->componentMap.find(c->name) == this->componentMap.end()) {
        this->componentMap.insert({c->name, std::unique_ptr<ze::Component>(c)});
        c->setGameObj(this);
    }
}


ze::Component* ze::GameObj::getComponent(const std::string& n) {
    const auto& c = this->componentMap.at(n);
    return c.get();
}


void ze::GameObj::rmvComponent(const std::string& n) {
    this->componentMap.erase(n);
}


void ze::GameObj::update(const float dt) {
    for (const auto& [name, component] : this->componentMap)
        component->update(dt);
}


void ze::GameObj::draw(sf::RenderWindow& window) {
    for (const auto& [name, component] : this->componentMap)
        component->draw(window);
}


void ze::GameObj::applyDamage(const float damage) {
    this->stats.lifePoints -= damage;
    if (this->stats.lifePoints < 0) {
        this->stats.lifePoints = 0;
    }
}