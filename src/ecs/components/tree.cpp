#include "../../../include/ecs/components/tree.hpp"



ze::Tree::Tree(

) : ze::Component("Tree"),
    sprite({ze::TREE_IMAGE_FILE}) {

}


void ze::Tree::update(const float) {

}


void ze::Tree::draw(sf::RenderWindow& window) {
    this->sprite.draw(window);
}


void ze::Tree::setGameObj(ze::GameObj* obj) {
    ze::Component::setGameObj(obj);
    this->sprite.setGameObj(obj);
    this->gameObj->transform.shrinkScale = {0.8, 0.5};
}