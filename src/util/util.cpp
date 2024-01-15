#include "../../include/util/util.hpp"


void ze::normalizeVector(sf::Vector2f& v) {
    const float magnitude = std::sqrt(v.x * v.x + v.y * v.y);
    if (magnitude > 1) {
        v.x /= magnitude;
        v.y /= magnitude;
    }
}