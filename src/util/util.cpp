//
// Created by vitor on 1/28/24.
//
#include "../../include/util/util.h"



void ze::normalizeVector(sf::Vector2f *v) {
    const float m = std::sqrt(v->x * v->x + v->y * v->y);
    if (m > 1) {
        v->x /= m;
        v->y /= m;
    }
}
