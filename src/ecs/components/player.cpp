#include "../../../include/ecs/components/player.hpp"
#include <iostream>

ze::Player::Player(

) : ze::Component("Player"),
    animationGroup("PlayerAnimation", ze::PLAYER_ANIMATIONS),
    attackTask(ze::PLAYER_ATTACK_TIME),
    damageTask(ze::PLAYER_DAMAGE_TIME),
    attackSpeedTimer(ze::PLAYER_ATTACK_SPEED) {

}


void ze::Player::handleMovement(const float dt) {
    ze::GameObjState& state = this->gameObj->state;
    if (
        state.action == ze::Action::Attack        
    ) {
        return;
    }

    sf::Vector2f& direction = this->gameObj->transform.direction;
    direction = {};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        state.direction = ze::Direction::Down;
        state.action = ze::Action::Moving;
        direction.y = 1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        state.direction = ze::Direction::Up;
        state.action = ze::Action::Moving;
        direction.y = -1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction.x = -1;
        state.direction = ze::Direction::Left;
        state.action = ze::Action::Moving;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        state.direction = ze::Direction::Right;
        state.action = ze::Action::Moving;
        direction.x = 1;
    }

    if (direction.x == 0.f && direction.y == 0.f) state.action = ze::Action::Idle;
    this->gameObj->transform.move(dt);   
}


void ze::Player::handleAttack() {
    ze::GameObjState& state = this->gameObj->state;
    if (
        state.action == ze::Action::Attack ||
        state.action == ze::Action::Damage ||
        sf::Keyboard::isKeyPressed(ze::ATTACK_KEY) == false ||
        this->attackSpeedTimer.check() == false
    ) {
        return;
    }
    this->attackSpeedTimer.reset();
    state.action = ze::Action::Attack;
    this->attackTask.start(
        [&state]() { 
            state.action = ze::Action::Idle;            
        }
    );
}


void ze::Player::update(const float dt) {
    this->handleAttack();
    this->handleMovement(dt);
    this->animationGroup.change(this->gameObj->state.toStr("player_"));
    this->animationGroup.update(dt);
}


void ze::Player::draw(sf::RenderWindow& window) {
    this->animationGroup.draw(window);
}


void ze::Player::applyDamage() {
    if (this->damageTask.is_running()) {
        return;
    }    
    this->gameObj->state.action = ze::Action::Damage;
    this->animationGroup.enableMask();
    this->damageTask.start(
        [this]() {
            this->gameObj->state.action = ze::Action::Idle;
            this->animationGroup.disableMask();
        }
    );
}


void ze::Player::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    this->animationGroup.setGameObj(gameObj);
    this->gameObj->stats.lifePoints = ze::PLAYER_LIFE_POINTS;
    this->gameObj->transform.speed = ze::PLAYER_SPEED;
    this->gameObj->transform.size = {ze::TILE_SIZE, ze::TILE_SIZE};
    this->gameObj->transform.setCenter(ze::SCREEN_CENTER);
}
