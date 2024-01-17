#include "../../include/group/camera.hpp"


og::Camera::Camera(

) : og::Group("camera") {
    for (const og::Zindex& index : og::zIndexVector) {
        this->objMap.insert({index, {}});
    }
}


void og::Camera::ySortObjs(std::vector<og::GameObj*>& v) {
    std::sort(
        v.begin(), v.end(),
        [] (og::GameObj* g1, og::GameObj* g2) {
            const float y1 = g1->transform.centerY();
            const float y2 = g2->transform.centerY();
            if (y1 == y2) return g1 < g2;
            return y1 < y2;
        }
    );
}



void og::Camera::draw(sf::RenderWindow& window) {
    for (auto& [zIndex, objVector] : this->objMap) {
        this->ySortObjs(objVector);
        for (og::GameObj* obj : objVector) {
            obj->draw(window);
        }
    }
}


void og::Camera::draw(sf::RenderWindow& window, const sf::Vector2f& offset) {
    for (auto& [zIndex, objVector] : this->objMap) {
        this->ySortObjs(objVector);
        for (og::GameObj* obj : objVector) {
            obj->draw(window);
        }
    }
}


bool og::Camera::contains(og::GameObj* obj) const {
    const std::vector<og::GameObj*>& objList = this->objMap.at(obj->transform.zIndex);
    for (og::GameObj* obj_ : objList) {
        if (obj_ == obj) return true;
    }
    return false;
}


void og::Camera::add(og::GameObj* obj) {
    this->objMap.at(obj->transform.zIndex).push_back(obj);
}



void og::Camera::rmv(og::GameObj* obj) {
    std::vector<og::GameObj*>& v = this->objMap.at(obj->transform.zIndex);
    for (std::size_t i = 0; i < v.size(); i++) {
        if (v.at(i) == obj) {
            v.erase(v.begin() + i);
            return;
        }
    }
}

