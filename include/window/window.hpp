#ifndef AF1BE35E_8923_4E47_B0A1_EEAAE21CA724
#define AF1BE35E_8923_4E47_B0A1_EEAAE21CA724
#include <SFML/Graphics.hpp>
#include <memory>
#include "../scene/scenes.hpp"
#include "../constants.hpp"

namespace og {


    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            std::unique_ptr<og::Scene> scene;
            og::ChangeScene changeScene;

        private:
            void handleInput();
            void update();
            void draw();

        public:
            Window();
            void run();

    };
    
} // namespace og


#endif /* AF1BE35E_8923_4E47_B0A1_EEAAE21CA724 */
