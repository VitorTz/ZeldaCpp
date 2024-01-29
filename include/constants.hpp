#ifndef ZELDACPP_CONSTANTS_H
#define ZELDACPP_CONSTANTS_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>
#include "util/Rect.hpp"


namespace ze {


    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const int FPS = 60;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);
    const std::string SCREEN_TITLE("Zelda");
    const ze::Rect SCREEN_RECT({{ }, SCREEN_SIZE});
    const sf::Color SCREEN_COLOR(113, 221, 238);

    const float PLAYER_SPEED = 250.f;    

}

#endif //ZELDACPP_CONSTANTS_H
