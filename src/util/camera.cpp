#include "../../include/util/camera.hpp"


ze::Camera::Camera() : ze::Group() {
    for (const ze::Zindex& index : ze::zIndexVector) {
        this->objMap.insert({index, {}});
    }
}


void ze::Camera::ySortObjs(std::vector<ze::GameObj*>& v) {
    std::sort(
        v.begin(), v.end(),
        [] (ze::GameObj* g1, ze::GameObj* g2) {
            const float y1 = g1->transform.centerY();
            const float y2 = g2->transform.centerY();
            if (y1 == y2) return g1 < g2;
            return y1 < y2;
        }
    );
}


void ze::Camera::draw(sf::RenderWindow& window) {
    for (auto& [zIndex, objVector] : this->objMap) {
        this->ySortObjs(objVector);
        for (ze::GameObj* obj : objVector) {
            obj->draw(window);
        }
    }
}


void ze::Camera::draw(sf::RenderWindow& window, const sf::Vector2f& offset) {
    for (auto& [zIndex, objVector] : this->objMap) {
        this->ySortObjs(objVector);
        for (ze::GameObj* obj : objVector) {
            obj->draw(window);
        }
    }
}


void ze::Camera::add(ze::GameObj* obj) {
    this->objs.insert(obj);
    this->objMap.at(obj->transform.zIndex).push_back(obj);
}



void ze::Camera::rmv(ze::GameObj* obj) {
    this->objs.erase(obj);
    std::vector<ze::GameObj*>& v = this->objMap.at(obj->transform.zIndex);
    for (std::size_t i = 0; i < v.size(); i++) {
        if (v[i] == obj) {
            v.erase(v.begin() + i);
            return;
        }
    }
}


void ze::Camera::clear() {
    this->objMap.clear();
    this->objs.clear();
}
