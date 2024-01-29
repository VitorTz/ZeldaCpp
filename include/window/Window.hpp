#ifndef ZELDACPP_WINDOW_HPP
#define ZELDACPP_WINDOW_HPP
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

        public:
            Window();
            void run();

        private:
            void handleInput();
            void update();
            void render();

    };
    
} // namespace ze




#endif