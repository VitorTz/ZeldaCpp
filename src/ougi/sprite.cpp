#include "../../include/ougi/sprite.hpp"


ze::ougi::Sprite::Sprite(

) {

}


ze::ougi::Sprite::Sprite(
    const std::string& imagePath,
    const ze::Rect& rect
) : imagePath(imagePath),
    rect(rect) {
    sf::Texture* t = ze::TexturePool::load(imagePath);
    this->sprite.setTexture(*t);
    this->rect.setSize((sf::Vector2f) t->getSize());
}


ze::ougi::Sprite::Sprite(
    const std::string& imagePath
) : Sprite(imagePath, {}) {

}


ze::ougi::Sprite::~Sprite() {
    ze::TexturePool::rmv(this->imagePath);
}


void ze::ougi::Sprite::update(const float& dt) {
    return;
}


void ze::ougi::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setPosition(this->rect.getPos());
    window.draw(this->sprite);
}


void ze::ougi::Sprite::draw(sf::RenderWindow& window, const ze::Rect& _rect) {
    this->sprite.setPosition(_rect.getPos());
    window.draw(this->sprite);
}

ze::Rect* ze::ougi::Sprite::getRect() {
    return &this->rect;
}


sf::Texture* ze::ougi::Sprite::getTexture() {
    sf::Texture* t = ze::TexturePool::load(this->imagePath);
    return t;
}