#include "../../../include/ecs/components/Sprite.hpp"


void ze::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setScale({gameObj->scale, gameObj->scale});
    this->sprite.setPosition(this->gameObj->rect.getPos());
    this->sprite.setRotation(gameObj->rotation);
    window.draw(this->sprite);
}


void ze::Sprite::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    this->gameObj->rect.setSize(
        (sf::Vector2f) this->sprite.getTexture()->getSize()
    );
}