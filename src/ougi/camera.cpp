#include "../../include/ougi/camera.hpp"


ze::ougi::Camera::Camera() {

}


ze::ougi::Camera::~Camera() {
    for (const auto& pair : this->groups)
        delete pair.second;
}



void ze::ougi::Camera::createGroup(const int& zIndex) {
    if (this->groups.find(zIndex) == this->groups.end()) {
        this->groups.insert({zIndex, new ze::ougi::Group(std::to_string(zIndex))});
    }
}


ze::ougi::Group* ze::ougi::Camera::getGroup(const int& zIndex) {
    this->createGroup(zIndex);
    return this->groups.at(zIndex);
}



void ze::ougi::Camera::update(const float& dt) {
    for (const auto& pair : this->groups)
        pair.second->update(dt);
}


void ze::ougi::Camera::draw(sf::RenderWindow& window) {
    for (const auto& pair : this->groups)
        pair.second->draw(window);
}


std::map<int, ze::ougi::Group*>& ze::ougi::Camera::getGroups() {
    return this->groups;
}