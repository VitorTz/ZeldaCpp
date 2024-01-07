#include "../../include/ougi/player.hpp"

ze::ougi::Player::Player(

    ) : ze::ougi::Sprite(),
        animation(ze::ougi::PLAYER_ANIMATIONS)
{
    this->rect.setSize(ze::PLAYER_SIZE);
    this->animation.change(ze::ougi::AnimationId::PlayerDownIdle);
}

ze::ougi::Player::~Player()
{
    ze::ougi::Sprite::~Sprite();
}

void ze::ougi::Player::move(const float &dt) {
    this->direction = {};
    this->horizontalDirection = ze::Direction::Idle;
    this->verticalDirection = ze::Direction::Idle;

    for (const auto &pair : ze::horizontalDirectionByKey)
        if (sf::Keyboard::isKeyPressed(pair.first))
        {
            this->direction.x = pair.second;
            this->horizontalDirection = pair.second;
        }

    for (const auto &pair : ze::verticalDirectionByKey)
        if (sf::Keyboard::isKeyPressed(pair.first))
        {
            this->direction.y = pair.second;
            this->verticalDirection = pair.second;
        }

    ze::normalizeVector(this->direction);

    this->rect.move(
        dt * this->direction.x * 300,
        dt * this->direction.y * 300);
}

void ze::ougi::Player::handleAnimationChange()
{
    ze::ougi::AnimationId id = this->animation.getAnimationId();

    if (this->horizontalDirection == this->verticalDirection == ze::Direction::Idle)
        

    switch (this->verticalDirection) {
        case ze::Direction::Up:
            this->animation.change(ze::ougi::PlayerUp);
            break;

        default:
            break;
    }
}

void ze::ougi::Player::update(const float &dt)
{
    this->move(dt);
    this->handleAnimationChange();
    this->animation.update(dt);
}

void ze::ougi::Player::draw(sf::RenderWindow &window)
{
    this->animation.draw(window, this->rect);
}