#include "../include/zelda.hpp"


void ze::initGame(ze::Window& w) {
    
    w.window.setFramerateLimit(ze::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    w.window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - ze::SCR_WIDTH / 2,
            desktop.height / 2 - ze::SCR_HEIGHT / 2
        )
    );

    ze::changeScene(ze::mainScene);

}


void ze::closeGame() {
    delete ze::scene;
}


void ze::runGame(ze::Window& w) {
    while (w.window.isOpen()) {
        ze::handleInput(w);
        ze::update(w);
        ze::draw(w);
    }
}