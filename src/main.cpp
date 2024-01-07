#include "../include/zelda.hpp"
#include "../include/constants.hpp"


int main() {
    ze::Window w{
        {sf::VideoMode(ze::SCR_WIDTH, ze::SCR_HEIGHT),
            ze::SCR_TITLE,
            sf::Style::Titlebar | sf::Style::Close
        },
        {}
    };
    ze::initGame(w);
    ze::runGame(w);
    ze::closeGame();
}