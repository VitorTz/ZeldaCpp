#include "../../include/util/util.hpp"


void og::normalizeVector(sf::Vector2f& v) {
    const float m = std::sqrt(v.x * v.x + v.y * v.y);
    if (m > 1) {
        v.x /= m;
        v.y /= m;
    }
}


int og::randomInt(const int start, const int end) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
    return dist(rng);
}