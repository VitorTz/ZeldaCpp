#pragma once
#include <SFML/System/Vector2.hpp>
#include <iostream>


namespace ze {


    template<typename T>
    void printVector(const sf::Vector2<T>&v ) {
        std::cout << "Vector(" << v.x << ", " << v.y << ")\n";
    }

    
} // namespace ze
