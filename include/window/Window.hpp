#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../constants.hpp"
#include "../scene/scenes.hpp"

namespace ze {


    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            std::unique_ptr<ze::Scene> scene;
            ze::ChangeScene changeScene;
        
        private:
            void initGame();
            void handleEvents();
            void update();
            void render();
        
        public:
            Window();
            void run();

    };
    
} // namespace ze
