#include "../../include/util/debug.hpp"


void ze::debug(sf::RenderWindow& window, std::unique_ptr<ze::GameObjPool>& gameObjPool) {
    if (!ze::DEBUG_MODE) {
        return;
    }

    const std::map<std::string, std::unique_ptr<ze::Group>>* groups = gameObjPool->getGroups();
    
    for (const ze::GameObj* obj : *groups->at("camera")->getObjs()) {
        ze::drawBorder(window, obj->transform, sf::Color::Red);
        ze::drawBorder(window, obj->transform.shrink(), sf::Color::Blue);
    }

    sf::Vector2f pos = {10.f, 10.f};
    for (const auto& [groupName, group] : *groups) {
        ze::Text::draw(
            window,
            groupName + "-> " + std::to_string(group->size()),
            18,
            pos,
            sf::Color::White
        );
        pos.y += 25;
    }
    ze::Text::draw(
        window,
        "all objs -> " + std::to_string(gameObjPool->size()),
        18,
        pos,
        sf::Color::White
    );
    
}