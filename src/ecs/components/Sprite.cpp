//
// Created by vitor on 1/28/24.
//
#include "../../../include/ecs/components/Sprite.h"


ze::Sprite::Sprite(
    const std::filesystem::path &source
) : ze::Component("Sprite-" + source.string()),
    source(source) {
    ze::TexturePool::load(&this->sprite, source);
}


ze::Sprite::~Sprite() {
    ze::TexturePool::erase(this->source);
}


void ze::Sprite::draw(sf::RenderWindow &window) {
    this->sprite.setPosition(this->gameObj->rect.getPos());
    this->sprite.setScale({this->gameObj->scale, this->gameObj->scale});
    this->sprite.setRotation(this->gameObj->rotation);
    window.draw(this->sprite);
}


void ze::Sprite::setGameObj(ze::GameObj *gameObj) {
    ze::Component::setGameObj(gameObj);
    gameObj->rect.setSize((sf::Vector2f) this->sprite.getTexture()->getSize());
}