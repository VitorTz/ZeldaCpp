#include "../../../include/ecs/component/Sprite.hpp"
#include <iostream>


ze::Sprite::Sprite(
    const std::filesystem::path& source
) : ze::Component("Sprite-" + source.string()),
    source(source) {
        ze::TexturePool::load(&sprite, source);
    }


ze::Sprite::~Sprite() {
    ze::TexturePool::erase(source);
}


void ze::Sprite::draw(sf::RenderWindow& window) {
    sprite.setPosition(gameObj->transform.pos);
    sprite.setScale(gameObj->transform.scale);
    sprite.setRotation(gameObj->transform.rotation);
    window.draw(sprite);
}


void ze::Sprite::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    gameObj->transform.size = (sf::Vector2f) sprite.getTexture()->getSize();
}