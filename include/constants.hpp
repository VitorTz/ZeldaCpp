#ifndef F14D934C_E9D4_4896_BA92_51EC995ED038
#define F14D934C_E9D4_4896_BA92_51EC995ED038
#include <SFML/System/Vector2.hpp>
#include "util/Rect.hpp"
#include <string>



namespace ze {


    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const std::string SCREEN_TITLE("SFML-TEMPLATE");
    const ze::Rect SCREEN_RECT({}, SCREEN_SIZE);
    const int FPS = 60;

    
} // namespace st


#endif /* F14D934C_E9D4_4896_BA92_51EC995ED038 */
