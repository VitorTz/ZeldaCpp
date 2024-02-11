#include "../../include/window/Window.hpp"


ze::Window::Window(

) : window(
    sf::VideoMode(ze::SCREEN_WIDTH, ze::SCREEN_HEIGHT),
    ze::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    window.setFramerateLimit(ze::FPS);
    
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - ze::SCREEN_WIDTH / 2,
            desktop.height / 2 - ze::SCREEN_HEIGHT / 2
        )
    );

    changeScene = [this](const ze::SceneId id) {
        switch (id) {
            case ze::SceneId::LevelScene:
                scene = std::make_unique<ze::Level>(this->changeScene);
                break;
            default:
                break;
        }
    };
    
    initGame();

}


void ze::Window::initGame() {
    changeScene(ze::mainScene);
}


void ze::Window::handleEvents() {
    sf::Event e;

    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}


void ze::Window::update() {
    const float dt = clock.restart().asSeconds();
    scene->update(dt);
}


void ze::Window::render() {
    window.clear();
    scene->draw(window);
    window.display();
}


void ze::Window::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}