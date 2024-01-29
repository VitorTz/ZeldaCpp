#include "../../include/util/util.hpp"


void ze::normalizeVector(sf::Vector2f *v) {
    const float m = std::sqrt(v->x * v->x + v->y * v->y);
    if (m > 1) {
        v->x /= m;
        v->y /= m;
    }
}


int ze::randomInt(int start, int end) {
    std::random_device os_seed;
    const uint_least32_t seed = os_seed();

    std::mt19937 generator( seed );
    std::uniform_int_distribution<int_least32_t> distribute( start, end);

    return distribute(generator);
}


void ze::printVector(const sf::Vector2f v) {
    std::cout << "Vector(" << v.x << ", " << v.y << ")\n";
}