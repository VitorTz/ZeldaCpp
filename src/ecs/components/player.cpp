#include "../../../include/ecs/components/player.hpp"


ze::Player::Player(

) : ze::Component("PlayerComponent"),
    animation(ze::AnimationId::PlayerAnimationId) {
    this->animation.change("down_idle");
}


void ze::Player::move(const float dt) {
    ze::Transform& t = this->gameObj->transform;
    t.direction = {0.f, 0.f};
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        t.direction.y = -1;
        this->gameObj->direction = ze::Direction::Up;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        t.direction.y = 1;
        this->gameObj->direction = ze::Direction::Down;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        t.direction.x = -1;
        this->gameObj->direction = ze::Direction::Left;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        t.direction.x = 1;
        this->gameObj->direction = ze::Direction::Right;
    }
    
    this->gameObj->state = (t.direction.x == 0.f && t.direction.y == 0.f) ? ze::GameObjState::Idle : ze::GameObjState::Moving;
    this->lastMovement = t.move(dt);
}


void ze::Player::undoLastMovement() {
    this->gameObj->transform.move(-this->lastMovement);
    this->lastMovement = {0.f, 0.f};
}


void ze::Player::update(const float dt) {
    this->move(dt);
    this->animation.change(
        ze::directionToStr.at(this->gameObj->direction) + '_' + ze::stateToStr.at(this->gameObj->state)
    );
    this->animation.update(dt);
}


void ze::Player::draw(sf::RenderWindow& window) {
    this->animation.draw(window);
}


void ze::Player::setGameObj(ze::GameObj* obj) {
    ze::Component::setGameObj(obj);
    this->animation.setGameObj(obj);    
    this->gameObj->transform.boxColliderScale = ze::PLAYER_BOX_COLLIDER_SCALE;
    this->gameObj->transform.speed = ze::PLAYER_SPEED;
}