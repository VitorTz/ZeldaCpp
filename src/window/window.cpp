#include "../../include/window/window.hpp"



void ze::handleInput(ze::Window& w) {
    sf::Event e;
    while (w.window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                w.window.close();
                break;
            default:
                break;
        }
    }
}


void ze::update(ze::Window& w) {
    const float dt = w.clock.restart().asSeconds();
    ze::globals::currentTime += dt;
    ze::scene->update(dt);
}

void ze::draw(ze::Window& w) {
    w.window.clear();
    ze::scene->draw(w.window);
    w.window.display();
}
