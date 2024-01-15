#include "../../../include/util/group/camera.hpp"


ze::Camera::Camera(

) : ze::Group("Camera"),
    offsetObj(nullptr) {
    for (const ze::Zindex& index : ze::zIndexVector) {
        this->objs.insert({index, {}});
    }
}


void ze::Camera::add(const std::shared_ptr<ze::GameObj>& obj) {
    this->objs.at(obj->transform.zIndex).insert(
        {
            obj->name,
            obj
        }
    );
}


void ze::Camera::rmv(const std::string& name, const ze::Zindex index) {
    this->objs.at(index).erase(name);
}


void ze::Camera::rmv(const std::string& name) {
    for (auto& [index, map] : this->objs) 
        map.erase(name);
}


ze::GameObj* ze::Camera::get(const std::string& name) {
    for (const auto& [index, map] : this->objs) {
        try {
            return map.at(name).get();
        } catch (std::out_of_range& e) {

        }   
    }
    return nullptr;
}


ze::GameObj* ze::Camera::get(const std::string& name, const ze::Zindex index) {
    try {
        return this->objs.at(index).at(name).get();
    } catch (std::out_of_range& e) {
        return nullptr;
    }
}


void ze::Camera::update(const float dt) {
    for (const auto& [index, map] : this->objs) {
        for (const auto& [name, obj] : map) {
            obj->update(dt);
        }
    }
}


void ze::Camera::draw(sf::RenderWindow& window) {
    const sf::Vector2f offset = this->offsetObj ? this->offsetObj->transform.center() : sf::Vector2f();
    for (const auto& [index, map] : this->objs) {
        for (const auto& [name, obj] : map) {
            ze::Transform& t = obj->transform;
            const sf::Vector2f objCenter = t.center();
            const sf::Vector2f delta = {
                offset.x - objCenter.x,
                offset.y - objCenter.y
            };
            t.move(delta);
            obj->draw(window);
            t.move(-delta);
        }
    }
}


void ze::Camera::setOffset(const std::shared_ptr<ze::GameObj>& obj) {
    this->offsetObj = obj;
}