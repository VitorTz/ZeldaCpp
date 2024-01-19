#include "../../include/ecs/ecs.hpp"
#include <iostream>


ze::GameObj::GameObj(
    const std::string& name,
    const ze::Zindex zIndex,
    const std::set<ze::Group*>& groups
) : name(name), 
    transform(ze::Transform(zIndex)), 
    state(ze::GameObjState::Idle){
    this->addToGroups(groups);
}


ze::GameObj::~GameObj() {    
    for (ze::Group* group : this->groups) {
        group->rmv(this);
    }
    this->groups.clear();
}


void ze::GameObj::update(const float dt) {
    for (const auto& [name, component] : this->componentMap)
        component->update(dt);
}


void ze::GameObj::draw(sf::RenderWindow& window) {
    for (const auto& [name, component] : this->componentMap)
        component->draw(window);
}


void ze::GameObj::addComponent(std::unique_ptr<ze::Component> component) {
    component->setGameObj(this);
    this->componentMap.insert({component->name, std::move(component)});
}


ze::Component* ze::GameObj::getComponent(const std::string& componentName) {
    try {
        return this->componentMap.at(componentName).get();
    } catch (std::out_of_range& e) { }
    return nullptr;
}


void ze::GameObj::addToGroup(ze::Group* group) {
    group->add(this);
    this->groups.insert(group);
}


void ze::GameObj::addToGroups(const std::set<ze::Group*>& groups) {
    for (ze::Group* group : groups) {
        group->add(this);
        this->groups.insert(group);
    }
}


void ze::GameObj::rmvFromGroup(ze::Group* group) {
    group->rmv(this);
    this->groups.erase(group);
}


void ze::GameObj::rmvFromAllGroups() {
    for (ze::Group* group : this->groups) {
        group->rmv(this);
    }
    this->groups.clear();
}

