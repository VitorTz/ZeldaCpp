//
// Created by vitor on 1/28/24.
//
#include "../../include/window/Camera.h"


void ze::Camera::add(ze::GameObj *gameObj) {
    ze::Group::add(gameObj);
    const int zIndex = gameObj->zIndex;
    if (this->gameObjsByIndex.find(zIndex) == this->gameObjsByIndex.end()) {
        this->gameObjsByIndex.insert({zIndex, {}});
    }
    this->gameObjsByIndex.at(zIndex).push_back(gameObj);
}


void ze::Camera::rmv(ze::GameObj *gameObj) {
    ze::Group::rmv(gameObj);
    for (auto& [zIndex, objs] : this->gameObjsByIndex) {
        for (std::size_t i = 0; i < objs.size(); i++) {
            if (objs[i] == gameObj) {
                objs.erase(objs.begin() + i);
                return;
            }
        }
    }
}


void ze::Camera::rmvAll() {
    ze::Group::rmvAll();
    this->gameObjsByIndex.clear();
}


void ze::Camera::sortObjsByYpos(std::vector<ze::GameObj *> &v) {
    std::sort(
        v.begin(),
        v.end()
    );
}


void ze::Camera::draw(sf::RenderWindow &window, const sf::Vector2f offset) {
    for (auto& [zIndex, objs] : this->gameObjsByIndex) {
        ze::Camera::sortObjsByYpos(objs);
        for (ze::GameObj* obj : objs) {
            obj->draw(window);
        }
    }
}