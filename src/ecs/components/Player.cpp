#include "../../../include/ecs/components/Player.hpp"


void ze::Player::update(float dt) {
    this->movement.update(dt);
    this->animation.update(dt);
}


void ze::Player::draw(sf::RenderWindow& window) {
    this->animation.draw(window);
}   


void ze::Player::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    this->animation.setGameObj(gameObj);
    this->movement.setGameObj(gameObj);
}