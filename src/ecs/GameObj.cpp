//
// Created by vitor on 1/28/24.
//
#include "../../include/ecs/ecs.h"


ze::GameObj::~GameObj() {
    for (ze::Group* group : this->groups) {
        group->rmv(this);
    }
}


void ze::GameObj::addComponent(std::unique_ptr<ze::Component> component) {
    component->setGameObj(this);
    this->componentMap.insert({component->name, std::move(component)});
}


ze::Component* ze::GameObj::getComponent(const std::string &componentName) {
    return this->componentMap.at(componentName).get();
}


void ze::GameObj::update(const float dt) {
    for (const auto& [componentName, component] : this->componentMap) {
        component->update(dt);
    }
}


void ze::GameObj::draw(sf::RenderWindow &window) {
    for (const auto& [componentName, component] : this->componentMap) {
        component->draw(window);
    }
}


void ze::GameObj::addToGroup(ze::Group *group) {
    group->add(this);
    this->groups.insert(group);
}


void ze::GameObj::rmvFromGroup(ze::Group *group) {
    this->groups.erase(group);
    group->rmv(this);
}

