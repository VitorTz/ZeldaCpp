#include "../../include/ougi/mask.hpp"



ze::ougi::Mask::Mask(
    ze::ougi::Sprite* sprite,
    const sf::Color& color
) : Mask(sprite->getTexture(), color) {
    
}


ze::ougi::Mask::Mask(
    sf::Texture* texture,
    const sf::Color& color
) : sprite(new sf::Sprite()),
    texture(new sf::Texture()) {
    sf::Image image(texture->copyToImage());
    const sf::Vector2u size = image.getSize();
    for (std::size_t i = 0; i < size.y; i++)
        for (std::size_t j = 0; j < size.x; j++)
            if (image.getPixel(j, i).toInteger() != 0)
                image.setPixel(j, i, color);
        
    this->texture->setSmooth(true);
    this->texture->loadFromImage(image);
    this->sprite->setTexture(*this->texture);
}


ze::ougi::Mask::~Mask() {
    delete this->texture;
    delete this->sprite;
}


void ze::ougi::Mask::draw(
    sf::RenderWindow& window,
    const ze::Rect& rect
) {
    this->sprite->setPosition(rect.getPos());
    window.draw(*this->sprite);
}