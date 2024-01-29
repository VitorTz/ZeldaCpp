#include "../../include/window/Camera.hpp"


void ze::Camera::sortObjByCenterY(std::vector<ze::GameObj*>* v) {
    std::sort(
        v->begin(), v->end(),
        [](ze::GameObj* g1, ze::GameObj* g2) {
            const float g1Y = g1->rect.centerY();
            const float g2Y = g2->rect.centerY();
            return g1Y == g2Y ? g1 < g2 : g1Y < g2Y;
        }
    );
}

void ze::Camera::draw(
    sf::RenderWindow& window,
    const sf::Vector2f offset
) {
    const sf::Vector2f cameraOffset = ze::SCREEN_CENTER - offset;
    const ze::Rect sRect = ze::SCREEN_RECT;
    for (auto& [index, objs] : this->gameObjByIndex) {
        ze::Camera::sortObjByCenterY(&objs);
        for (ze::GameObj* obj : objs) {
            obj->rect.move(cameraOffset);
            if (ze::Rect::collide(obj->rect, sRect)) {
                obj->draw(window);
            }
            obj->rect.move(-cameraOffset);
        }
    }   
}


void ze::Camera::add(ze::GameObj* obj) {
    ze::Group::add(obj);
    const int zIndex = obj->zIndex;
    if (this->gameObjByIndex.find(zIndex) == this->gameObjByIndex.end()) {
        this->gameObjByIndex.insert({zIndex, {}});
    }
    this->gameObjByIndex.at(zIndex).push_back(obj);
}


void ze::Camera::erase(ze::GameObj* obj) {
    ze::Group::erase(obj);
    std::vector<ze::GameObj*>& objs = this->gameObjByIndex.at(obj->zIndex);
    for (std::size_t i = 0; i < objs.size(); i++) {
        if (objs[i] == obj) {
            objs.erase(objs.begin() + i);
            return;
        }
    }
}
