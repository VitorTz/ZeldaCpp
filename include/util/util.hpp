#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <cmath>
#include <iostream>


namespace ze {


    void normalizeVector(sf::Vector2f& v);

    template<typename T>
    void printVector(const sf::Vector2<T> v) {
        std::cout << "Vector(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")\n";
    }
    
} // namespace ze
