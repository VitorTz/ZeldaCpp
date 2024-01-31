#include "../../include/util/Rect.hpp"



float ze::Rect::left() const {
    return pos.x;
}


float ze::Rect::right() const {
    return pos.x + size.x;
}


float ze::Rect::top() const {
    return pos.y;
}


float ze::Rect::bottom() const {
    return pos.y + size.y;
}


void ze::Rect::setLeft(const float l) {
    pos.x = l;
}


void ze::Rect::setTop(const float t) {
    pos.y = t;
}


void ze::Rect::setBottom(const float b) {
    pos.y = b - size.y;
}


void ze::Rect::setRight(const float r) {
    pos.x = r - size.x;
}


sf::Vector2f ze::Rect::center() const {
    return {pos.x + size.x / 2, pos.y + size.y / 2};
}


float ze::Rect::centerX() const {
    return pos.x + size.x / 2;
}


float ze::Rect::centerY() const {
    return pos.y + size.y / 2;
}


void ze::Rect::setCenterX(const float x) {
    pos.x = x - size.x / 2;
}


void ze::Rect::setCenterY(const float y) {
    pos.y = y - size.y / 2;
}


float ze::Rect::width() const {
    return size.x;
}


float ze::Rect::height() const {
    return size.y;
}


bool ze::Rect::collide(const ze::Rect& r1, const ze::Rect& r2) {
    if (r1.left() > r2.right() || r1.right() < r2.left()) {
        return false;
    }

    if (r1.top() > r2.bottom() || r1.bottom() < r2.top()) {
        return false;
    }
    
    return true;
}