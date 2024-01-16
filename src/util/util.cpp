#include "../../include/util/util.hpp"


void ze::normalizeVector(sf::Vector2f& v) {
    const float magnitude = std::sqrt(v.x * v.x + v.y * v.y);
    if (magnitude > 1) {
        v.x /= magnitude;
        v.y /= magnitude;
    }
}

int ze::randomInt(const int start, const int end) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return dist(rng);
}