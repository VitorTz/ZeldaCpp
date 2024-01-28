//
// Created by vitor on 1/28/24.
//

#ifndef ZELDACPP_WINDOW_H
#define ZELDACPP_WINDOW_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "../scene/scenes.h"
#include "../Constants.h"


namespace ze {

    class Window {

    private:
        sf::RenderWindow window;
        sf::Clock clock;
        ze::ChangeScene changeScene;
        std::unique_ptr<ze::Scene> scene;

    private:
        void handleInput();
        void update();
        void render();

    public:
        Window();
        ~Window() = default;
        void run();

    };

}

#endif //ZELDACPP_WINDOW_H
