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