#ifndef ZELDACPP_UTIL_H
#define ZELDACPP_UTIL_H
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>
#include <random>


namespace ze {


    void normalizeVector(sf::Vector2f *v);

    int randomInt(int start, int end);

    void printVector(const sf::Vector2f v);
    


}

#endif //ZELDACPP_UTIL_H
