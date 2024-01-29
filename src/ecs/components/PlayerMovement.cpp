#include "../../../include/ecs/components/PlayerMovement.hpp"


void ze::PlayerMovement::update(const float dt) {
    this->directionVec.x = 0.f;
    this->directionVec.y = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->directionVec.y = -1;
        this->direction = ze::Direction::Up;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->directionVec.y = 1;
        this->direction = ze::Direction::Down;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->directionVec.x = -1;
        this->direction = ze::Direction::Left;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->directionVec.x = 1;
        this->direction = ze::Direction::Right;
    }

    ze::normalizeVector(&this->directionVec);
    this->gameObj->lastMovement = {
        this->gameObj->speed * this->directionVec.x * dt,
        this->gameObj->speed * this->directionVec.y * dt
    };
    
    this->isMoving_ = this->directionVec.x != 0 || this->directionVec.y != 0;
    this->gameObj->rect.move(this->gameObj->lastMovement);

}

