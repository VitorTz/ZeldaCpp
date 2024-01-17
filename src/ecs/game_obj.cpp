#include "../../include/ecs/ecs.hpp"


og::GameObj::GameObj(
    const std::string& name,
    const og::Zindex zIndex
) : og::GameObj(name, og::Transform(zIndex)) {
    
}

og::GameObj::GameObj(
    const std::string& name,
    const og::Transform& transform
) : name(name),
    transform(transform) {
        
    }


og::GameObj::~GameObj() = default;


void og::GameObj::update(const float dt) {
    for (const auto& [name, component] : this->componentMap)
        component->update(dt);
}


void og::GameObj::draw(sf::RenderWindow& window) {
    for (const auto& [name, component] : this->componentMap)
        component->draw(window);
}


void og::GameObj::addComponent(std::unique_ptr<og::Component> component) {
    component->setGameObj(this);
    this->componentMap.insert({component->name, std::move(component)});
}


void og::GameObj::addGroup(const std::string& name) {
    this->groups.insert(name);
}


const std::set<std::string>& og::GameObj::getGroups() const {
    return this->groups;
}