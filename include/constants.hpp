#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>


namespace ze {

    const int SCR_WIDTH = 1280;
    const int SCR_HEIGHT = 720;
    const std::string SCR_TITLE = "Zelda";
    const int FPS = 60;
    const sf::Vector2f SCR_SIZE(SCR_WIDTH, SCR_HEIGHT);
    const sf::Vector2f SCR_CENTER(SCR_WIDTH / 2, SCR_HEIGHT / 2);

    const sf::Vector2f TILE_SIZE(64, 64);
    const sf::Vector2f PLAYER_SIZE(64, 64);
    

    
} // namespace ze

