#ifndef C8937AFD_0009_424E_B9DF_8968FF909DEC
#define C8937AFD_0009_424E_B9DF_8968FF909DEC
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
#include <iostream>
#include "transform.hpp"


namespace ze {


    void normalizeVector(sf::Vector2f& v);
    int randomInt(const int start, const int end);

    template<typename T>
    T& choice(std::vector<T>& v) {        
        return v[ze::randomInt(0, v.size())];
    }

    void drawBorder(
        sf::RenderWindow& window,
        const ze::Transform& t, 
        const sf::Color& color
    );

    template<typename T>
    void printVector(const sf::Vector2<T>& v) {
        std::cout << "Vector(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ')' << '\n';
    }
    
} // namespace ze


#endif /* C8937AFD_0009_424E_B9DF_8968FF909DEC */
