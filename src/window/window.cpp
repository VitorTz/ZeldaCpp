#include "../../include/window/window.hpp"



og::Window::Window(

) : window(
    sf::VideoMode(og::SCREEN_WIDTH, og::SCREEN_HEIGHT),
    og::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    this->window.setFramerateLimit(og::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - og::SCREEN_WIDTH / 2,
            desktop.height / 2 - og::SCREEN_HEIGHT / 2
        )
    );
    this->changeScene = [this](const og::SceneId id) {
        if (this->scene == nullptr || this->scene->id != id) {
            switch (id) {
                case og::SceneId::LevelId:
                    this->scene.reset(new og::Level(this->changeScene));
                    break;
                default:
                    break;
            }
        }
    };

    this->changeScene(og::mainScene);

}


void og::Window::handleInput() {
    sf::Event e;
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


void og::Window::update() {
    const float dt = this->clock.restart().asSeconds();
    this->scene->update(dt);
}


void og::Window::draw() {
    this->window.clear();
    this->scene->draw(this->window);
    this->window.display();
}


void og::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->draw();
    }
}