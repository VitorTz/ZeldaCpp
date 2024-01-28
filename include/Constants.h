//
// Created by vitor on 1/28/24.
//

#ifndef ZELDACPP_CONSTANTS_H
#define ZELDACPP_CONSTANTS_H
#include <SFML/System/Vector2.hpp>
#include <string>

namespace ze {


    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const int FPS = 60;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);
    const std::string SCREEN_TITLE("Zelda");

}

#endif //ZELDACPP_CONSTANTS_H
