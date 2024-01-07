#include "../../include/util/rect.hpp"



ze::Rect::Rect() {

}


ze::Rect::Rect(
    const sf::Vector2f& pos,
    const sf::Vector2f& size
) : pos(pos),
    size(size) {

    }



const sf::Vector2f& ze::Rect::getPos() const {
    return this->pos;
}

const sf::Vector2f& ze::Rect::getSize() const {
    return this->size;
}


void ze::Rect::setSize(const sf::Vector2f& size) {
    this->size = size;
}


void ze::Rect::setPos(const sf::Vector2f& pos) {
    this->pos = pos;
}


float ze::Rect::left() const {
    return this->pos.x;
}


float ze::Rect::right() const {
    return this->pos.x + this->size.x;
}


float ze::Rect::bottom() const {
    return this->pos.y + this->size.y;
}


float ze::Rect::top() const {
    return this->pos.y;
}


void ze::Rect::setLeft(const float& left) {
    this->pos.x = left;
}


void ze::Rect::setTop(const float& top) {
    this->pos.y = top;
}


void ze::Rect::setBottom(const float& bottom) {
    this->pos.y = bottom - this->size.y;
}


void ze::Rect::setRight(const float& right) {
    this->pos.x = right - this->size.x;
}


void ze::Rect::move(const sf::Vector2f& v) {
    this->pos.x += v.x;
    this->pos.y += v.y;
}


void ze::Rect::move(const float& x, const float& y) {
    this->pos.x += x;
    this->pos.y += y;
}