#ifndef A95E0355_2022_4DCD_9859_DED30E9994F6
#define A95E0355_2022_4DCD_9859_DED30E9994F6
#include <SFML/System/Vector2.hpp>
#include <string>
#include <map>

namespace ze {


    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(ze::SCREEN_WIDTH, ze::SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(ze::SCREEN_WIDTH / 2, ze::SCREEN_HEIGHT / 2);
    const std::string SCREEN_TITLE = "Zelda";
    const int FPS = 60;
    const bool DEBUG_MODE = false;

    const float PLAYER_SPEED = 250.f;
    const float ANIMATION_SPEED = 6;
    const sf::Vector2f PLAYER_BOX_COLLIDER_SCALE(0.8f, 0.5f);

    
} // namespace ze


#endif /* A95E0355_2022_4DCD_9859_DED30E9994F6 */

