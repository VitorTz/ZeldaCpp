#include "../../include/ecs/ecs.hpp"


ze::Component::Component(
    const std::string& name
) : name(name) {
    std::cout << name << " created\n";
}


ze::Component::~Component() {
    std::cout << name << " deleted\n";
}


void ze::Component::update(const float& dt) {

}


void ze::Component::draw(sf::RenderWindow& window) {

}


void ze::Component::setGameObj(ze::GameObj* gameObj) {
    this->gameObj = gameObj;
}


ze::GameObj::GameObj(
    std::string&& name
) : name(name) {
    std::cout << this->name << " created\n";
}   


ze::GameObj::~GameObj() {
    std::cout << this->name << " deleted\n";
}


ze::GameObj::GameObj(
    std::string&& name,
    ze::Transform&& transform
) : name(name),
    transform(transform) {
        std::cout << name << " created\n";
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


void ze::GameObj::update(const float& dt) {
    for (const auto& [name, component] : this->componentMap)
        component->update(dt);
}


void ze::GameObj::draw(sf::RenderWindow& window) {
    for (const auto& [name, component] : this->componentMap)
        component->draw(window);
}