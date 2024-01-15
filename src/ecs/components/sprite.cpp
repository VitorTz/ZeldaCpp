#include "../../../include/ecs/components/sprite.hpp"


ze::Sprite::Sprite(
    const std::string& name,
    const ze::ImageSource& source
) : ze::Component(name),
    source(source) {
    ze::TexturePool::load(this->sprite, source);
}


ze::Sprite::Sprite(
    const ze::ImageSource& imageSource 
) : ze::Sprite(imageSource.path, imageSource) {

}


ze::Sprite::~Sprite() {
    ze::TexturePool::rmv(this->source.path);
}


void ze::Sprite::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    this->gameObj->transform.size = (sf::Vector2f) this->sprite.getTexture()->getSize();
}


void ze::Sprite::draw(sf::RenderWindow& window) {
    const ze::Transform& t = this->gameObj->transform;
    this->sprite.setPosition(t.pos);
    this->sprite.setScale(t.scale);
    window.draw(this->sprite);
}


const ze::ImageSource& ze::Sprite::getSource() const {
    return this->source;
}