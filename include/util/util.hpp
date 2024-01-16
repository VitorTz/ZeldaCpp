#ifndef A544F043_735B_41C9_B0D2_246A290B987B
#define A544F043_735B_41C9_B0D2_246A290B987B
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>
#include <random>
#include <chrono>


namespace ze {


    void normalizeVector(sf::Vector2f& v);

    int randomInt(const int start, const int end);

    template<typename T>
    void printVector(const sf::Vector2<T>& v) {
        std::cout << 
        "Vector(" << 
        v.x << 
        ", " << 
        v.y << 
        ')' << 
        '\n';
    }
    
} // namespace ze


#endif /* A544F043_735B_41C9_B0D2_246A290B987B */
