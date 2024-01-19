#ifndef AF1BE35E_8923_4E47_B0A1_EEAAE21CA724
#define AF1BE35E_8923_4E47_B0A1_EEAAE21CA724
#include <SFML/Graphics.hpp>
#include <memory>
#include "../scene/scenes.hpp"
#include "../constants.hpp"

namespace ze {


    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            std::unique_ptr<ze::Scene> scene;
            ze::ChangeScene changeScene;

        private:
            void handleInput();
            void update();
            void draw();

        public:
            Window();
            void run();

    };
    
} // namespace ze


#endif /* AF1BE35E_8923_4E47_B0A1_EEAAE21CA724 */
