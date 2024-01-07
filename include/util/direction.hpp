#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <map>


namespace ze {

    enum Direction {
        Down = 1,
        Left = -1,
        Right = 1,
        Up = -1,
        Idle = 0
    };


    const std::map<sf::Keyboard::Key, ze::Direction> horizontalDirectionByKey = {
        {sf::Keyboard::Left, ze::Direction::Left},
        {sf::Keyboard::Right, ze::Direction::Right}
    };


    const std::map<sf::Keyboard::Key, ze::Direction> verticalDirectionByKey = {
        {sf::Keyboard::Up, ze::Direction::Up},
        {sf::Keyboard::Down, ze::Direction::Down}
    };


} // namespace ze
