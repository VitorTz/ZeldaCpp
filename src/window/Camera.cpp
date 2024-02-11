#include "../../include/window/Camera.hpp"


ze::Camera::Camera() : ze::Group(ze::GroupId::CameraGroup) { }


void ze::Camera::insert(ze::GameObj* obj) {
    const int zIndex = obj->zIndex;
    if (objMap.find(zIndex) == objMap.end()) {
        objMap.insert({zIndex, {}});
    }
    objMap.at(zIndex).push_back(obj);    
}


void ze::Camera::erase(ze::GameObj* obj) {
    std::vector<ze::GameObj*>& v = objMap.at(obj->zIndex);
    for (std::size_t i = 0; i < v.size(); i++) {
        if (v[i] == obj) {
            v.erase(v.begin() + i);
            return;
        }
    }
}


void ze::Camera::clear() {
    objMap.clear();
}


void ze::Camera::sortObjsByCenterY(std::vector<ze::GameObj*>& v) {
    std::sort(
        v.begin(), v.end(),
        [](ze::GameObj* g1, ze::GameObj* g2) {
            const float g1Y = g1->transform.centerY();
            const float g2Y = g2->transform.centerY();
            return g1Y == g2Y ? g1 < g2 : g1Y < g2Y;
        }
    );
}


void ze::Camera::draw(sf::RenderWindow& window, const sf::Vector2f offset) {
    const sf::Vector2f cameraOffset = offset - ze::SCREEN_CENTER;    
    for (auto& [index, objs] : objMap) {        
        ze::Camera::sortObjsByCenterY(objs);
        for (ze::GameObj* obj : objs) {
            obj->transform.move(-cameraOffset);
            obj->draw(window);
            obj->transform.move(cameraOffset);
        }
    }
}