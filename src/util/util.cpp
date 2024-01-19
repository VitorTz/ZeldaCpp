#include "../../include/util/util.hpp"


void ze::normalizeVector(sf::Vector2f& v) {
    const float m = std::sqrt(v.x * v.x + v.y * v.y);
    if (m > 1) {
        v.x /= m;
        v.y /= m;
    }
}


int ze::randomInt(const int start, const int end) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return dist(rng);
}


void ze::drawBorder(
    sf::RenderWindow& window,
    const ze::Transform& t, 
    const sf::Color& color
) {
    const float thickness = 2;
    sf::RectangleShape rect;
    rect.setFillColor(color);
    
    rect.setSize({t.width(), thickness});
    rect.setPosition(t.pos);
    window.draw(rect);

    rect.setPosition({t.left(), t.bottom() - thickness});
    window.draw(rect);

    rect.setSize({thickness, t.height()});
    rect.setPosition(t.pos);
    window.draw(rect);

    rect.setPosition({t.right() -thickness, t.top()});
    window.draw(rect);
}