#include "../../include/window/Camera.hpp"


ze::Camera::Camera(

) : ze::Group(ze::GroupId::CameraGroup) {

}


void ze::Camera::insert(ze::GameObj* obj) {
    const int zIndex = obj->zIndex;
    if (objMap.find(zIndex) == objMap.end()) {
        objMap.insert({zIndex, {}});
    }
    objMap.at(zIndex).push_back(obj);
}


void ze::Camera::insert(
    const std::unique_ptr<ze::GameObj>& obj
) {
    insert(obj.get());
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
        v.begin(), v.end()
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