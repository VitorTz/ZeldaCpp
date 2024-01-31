#ifndef D5FC8966_D223_476A_A92A_E8A0F156F35A
#define D5FC8966_D223_476A_A92A_E8A0F156F35A
#include <SFML/Graphics.hpp>
#include <memory>
#include "../scene/scenes.hpp"
#include "../constants.hpp"


namespace ze {


    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            ze::ChangeScene changeScene;
            std::unique_ptr<ze::Scene> scene;
        
        private:
            void checkEvents();
            void update();
            void render();

        public:
            Window();
            void run();

    };
    
} // namespace st


#endif /* D5FC8966_D223_476A_A92A_E8A0F156F35A */
