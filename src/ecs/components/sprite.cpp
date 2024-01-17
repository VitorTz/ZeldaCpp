#include "../../../include/ecs/components/sprite.hpp"


og::Sprite::Sprite(
    const std::string& name,
    const std::filesystem::path& path
) : og::Component(name),
    path(path) {
    og::TexturePool::load(this->sprite, path);
}


og::Sprite::Sprite(
    const std::filesystem::path& path 
) : og::Sprite(path.string(), path) {

}


void og::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setPosition(this->gameObj->transform.pos);
    window.draw(this->sprite);
}


void og::Sprite::setGameObj(og::GameObj* gameObj) {
    og::Component::setGameObj(gameObj);
    this->gameObj->transform.size = (sf::Vector2f) this->sprite.getTexture()->getSize();
}