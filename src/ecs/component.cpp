#include "../../include/ecs/ecs.hpp"


og::Component::Component(
    const std::string& name
) : name(name) {

}

og::Component::~Component() = default;


void og::Component::update([[maybe_unused]] const float dt) {

}


void og::Component::draw([[maybe_unused]] sf::RenderWindow& window) {

}


void og::Component::setGameObj(og::GameObj* gameObj) {
    this->gameObj = gameObj;
}