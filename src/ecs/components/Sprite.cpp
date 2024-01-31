#include "../../../include/ecs/components/Sprite.hpp"


ze::Sprite::Sprite(
    const std::filesystem::path& source
) : ze::Component("Sprite-" + source.string()),
    source(source) {
        ze::TexturePool::load(&this->sprite, this->source);
    }


ze::Sprite::~Sprite() {
    ze::TexturePool::erase(this->source);
}


void ze::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setScale(this->gameObj->scale);
    this->sprite.setPosition(this->gameObj->rect.pos);    
    this->sprite.setRotation(this->gameObj->rotation);
    window.draw(this->sprite);
}


void ze::Sprite::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    this->gameObj->rect.size = (sf::Vector2f) this->sprite.getTexture()->getSize();
}