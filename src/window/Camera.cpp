#include "../../include/window/Camera.hpp"


ze::Camera::Camera() : ze::Group(ze::GroupId::CameraGroup) {
    for (const ze::Zindex index : ze::allZindex) {
        this->objsByIndex.insert({index, {}});
    }
}


void ze::Camera::insert(ze::GameObj* gameObj) {        
    ze::Group::insert(gameObj);    
    this->objsByIndex.at(gameObj->zIndex).push_back(gameObj);
}


void ze::Camera::erase(ze::GameObj* gameObj) {
    ze::Group::erase(gameObj);   
    gameObj->isVisible = false;
}


void ze::Camera::rmvFromCamera(ze::GameObj* gameObj) {
    std::vector<ze::GameObj*>& v = this->objsByIndex.at(gameObj->zIndex);
    for (std::size_t i = 0; i < v.size(); i++) {
        if (v[i] == gameObj) {
            v.erase(v.begin() + i);
            return;
        }
    }
}


void ze::Camera::sortByYpos(std::vector<ze::GameObj*>& v) {
    std::sort(
        v.begin(),
        v.end(),
        [](ze::GameObj* g1, ze::GameObj* g2) {
            const float g1Y = g1->rect.centerY();
            const float g2Y = g2->rect.centerY();
            return g1Y == g2Y ? g1 < g2 : g1Y < g2Y;
        }
    );
}


void ze::Camera::draw(sf::RenderWindow& window, const sf::Vector2f offset) {
    const sf::Vector2f cameraOffset = offset - ze::SCREEN_CENTER;
    const ze::Rect scrRect = ze::SCREEN_RECT;
    for (auto& [index, objs] : this->objsByIndex) {        
        ze::Camera::sortByYpos(objs);
        for (ze::GameObj* obj : objs) {
            obj->rect.pos -= cameraOffset;
            if (obj->isVisible && ze::Rect::collide(scrRect, obj->rect)) {
                obj->draw(window);
            }
            obj->rect.pos += cameraOffset;
        }
    }
}