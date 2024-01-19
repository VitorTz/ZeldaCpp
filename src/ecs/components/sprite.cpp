#include "../../../include/ecs/components/sprite.hpp"


ze::Sprite::Sprite(    
    const std::filesystem::path& path,
    const sf::Vector2f& boxColliderScale
) : ze::Component(path.stem().string()),
    path(path),
    boxColliderScale(boxColliderScale) {
    ze::TexturePool::load(this->sprite, path);
}

ze::Sprite::Sprite(
    const std::filesystem::path& path
) : ze::Sprite(path, sf::Vector2f()) {

}

ze::Sprite::Sprite(
    const ze::MapObj& mapObj
) : ze::Sprite(mapObj.imagePath, mapObj.boxColliderScale) {

}


void ze::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setPosition(this->gameObj->transform.pos);
    window.draw(this->sprite);
}


void ze::Sprite::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    this->gameObj->transform.size = (sf::Vector2f) this->sprite.getTexture()->getSize();
    this->gameObj->transform.boxColliderScale = this->boxColliderScale;
}