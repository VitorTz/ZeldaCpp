#include "../../include/window/Window.hpp"


ze::Window::Window(

) : window(
    sf::VideoMode(ze::SCREEN_WIDTH, ze::SCREEN_HEIGHT),
    ze::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar   
) {
    this->window.setFramerateLimit(ze::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - ze::SCREEN_WIDTH / 2,
            desktop.height / 2 - ze::SCREEN_HEIGHT / 2
        )
    );

    this->changeScene = [this](const ze::SceneId id) {
        if (this->scene == nullptr || this->scene->id != id) {
            switch (id) {
                case ze::SceneId::LevelId:
                    this->scene = std::make_unique<ze::Level>(this->changeScene);
                    break;
                default:
                    break;
            }
        }
    };

    this->changeScene(ze::mainScene);

}



void ze::Window::handleInput() {
    sf::Event e{};

    while (this->window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                this->window.close();
                break;    
            default:
                break;
        }
    }
}


void ze::Window::update() {
    const float dt = this->clock.restart().asSeconds();
    this->scene->update(dt);
}


void ze::Window::render() {
    this->window.clear(ze::SCREEN_COLOR);
    this->scene->draw(this->window);
    this->window.display();
}


void ze::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->render();
    }
}