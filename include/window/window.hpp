#pragma once
#include <SFML/Graphics.hpp>
#include "../scene/scenes.hpp"
#include "../globals.hpp"



namespace ze {

    typedef struct Window {
        sf::RenderWindow window;
        sf::Clock clock;
    } Window;

    void handleInput(ze::Window& w);
    void update(ze::Window& w);
    void draw(ze::Window& w);
    
} // namespace ze
