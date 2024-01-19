#include "../../include/util/text.hpp"



ze::Text::Text(
    const std::string& txt,
    const std::size_t size,    
    const sf::Color& color
) {
    this->font.loadFromFile("res/graphics/font/joystix.ttf");
    this->text.setFont(this->font);
    this->text.setString(txt);
    this->text.setCharacterSize(size);
    this->text.setFillColor(color);
    sf::FloatRect f = this->text.getLocalBounds();
    this->transform.size = {
        f.width,
        f.height
    };
}


void ze::Text::draw(sf::RenderWindow& window) {
    this->text.setPosition(this->transform.pos);
    window.draw(this->text);
}


void ze::Text::draw(
    sf::RenderWindow& window,
    const std::string& txt,
    std::size_t size,
    const sf::Vector2f& pos,
    const sf::Color& color
) {
    ze::Text t(txt, size, color);
    t.transform.pos = pos;
    t.draw(window);
}