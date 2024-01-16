#include "../../../include/util/group/camera.hpp"
#include <iostream>

ze::Camera::Camera(

) : ze::Group("camera") {
    for (const ze::Zindex& index : ze::zIndexVector) {
        this->objs.insert({index, {}});
    }
}


void ze::Camera::add(const std::shared_ptr<ze::GameObj>& obj) {
    this->objs.at(obj->transform.zIndex).push_back(obj);
}


void ze::Camera::rmv(const std::shared_ptr<ze::GameObj>& obj) {
    std::vector<std::shared_ptr<ze::GameObj>>& v = this->objs.at(obj->transform.zIndex);
    for (std::size_t i = 0 ; i < v.size(); i++) {
        if (v.at(i) == obj) {
            v.erase(v.begin() + i);
            break;
        }
    }
    std::cout << "rmv from " << this->name << '\n';
}


void ze::Camera::update(const float dt) {
    for (const auto& [index, set] : this->objs)
        for (const auto& obj : set)
            obj->update(dt);
}


inline void ze::Camera::sortObjVector(std::vector<std::shared_ptr<ze::GameObj>>& v) {
    std::sort(
        v.begin(), v.end(),
        [] (const std::shared_ptr<ze::GameObj>& g1, const std::shared_ptr<ze::GameObj>& g2) {
            const float x1 = g1->transform.centerY();
            const float x2 = g2->transform.centerY();
            if (x1 == x2) return g1->name < g2->name;
            return x1 < x2;
        }
    );
}


void ze::Camera::draw(sf::RenderWindow& window) {
    for (auto& [index, v] : this->objs) {
        this->sortObjVector(v);
        for (const auto& obj : v) {
            obj->draw(window);
        }
    }
}


void ze::Camera::draw(sf::RenderWindow& window, const sf::Vector2f& offset) {
    for (auto& [index, v] : this->objs) {
        this->sortObjVector(v);
        for (const auto& obj : v) {
            /*
            ze::Transform& t = obj->transform;
            const sf::Vector2f objCenter = t.center();
            const sf::Vector2f delta = {
                offset.x - objCenter.x,
                offset.y - objCenter.y
            };
            t.move(delta);
            t.move(-delta);
            */
            obj->draw(window);
        }
    }
}

