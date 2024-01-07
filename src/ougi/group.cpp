#include "../../include/ougi/group.hpp"


ze::ougi::Group::Group(
    const std::string& name 
) : name(name) {

}


ze::ougi::Group::~Group() {
    for (ze::ougi::Sprite* s : this->sprites)
        delete s;
    this->sprites.clear();
}


void ze::ougi::Group::add(ze::ougi::Sprite* sprite) {
    this->sprites.insert(sprite);
}


void ze::ougi::Group::rmv(ze::ougi::Sprite* sprite) {
    this->sprites.erase(sprite);
    delete sprite;
}


bool ze::ougi::Group::has(ze::ougi::Sprite* sprite) const {
    return (this->sprites.find(sprite) != this->sprites.end());
}


void ze::ougi::Group::update(const float& dt) {
    for (ze::ougi::Sprite* s : this->sprites)
        s->update(dt);
}


void ze::ougi::Group::draw(sf::RenderWindow& window) {    
    for (ze::ougi::Sprite* s : this->sprites)
        s->draw(window);
}


bool ze::ougi::Group::empty() const {
    return this->sprites.empty();
}


void ze::ougi::Group::clear() {
    for (ze::ougi::Sprite* s : this->sprites)
        delete s;
    this->sprites.clear();
}


std::unordered_set<ze::ougi::Sprite*>& ze::ougi::Group::getSprites() {
    return this->sprites;
}