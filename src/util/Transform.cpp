#include "../../include/util/Transform.hpp"


ze::Transform::Transform(
    const sf::Vector2f pos,
    const sf::Vector2f size,
    const sf::Vector2f boxCollideScale,
    const sf::Vector2f direction,
    const float scale,
    const float rotation,
    const float speed
) : pos(pos),
    size(size),
    boxCollideScale(boxCollideScale),
    direction(direction),
    scale(scale),
    rotation(rotation),
    speed(speed) {

}


float ze::Transform::left() const {
    return pos.x;
}

float ze::Transform::bottom() const {
    return pos.y + size.y;
}


float ze::Transform::right() const {
    return pos.x + size.x;
}


float ze::Transform::top() const {
    return pos.y;
}


void ze::Transform::setLeft(const float left) {
    pos.x = left;
}


void ze::Transform::setTop(const float top) {
    pos.y = top;
}


void ze::Transform::setRight(const float right) {
    pos.x = right - size.x;
}


void ze::Transform::setBottom(const float bottom) {
    pos.y = bottom - size.y;
}


float ze::Transform::width() const {
    return size.x;
}


float ze::Transform::height() const {
    return size.y;
}


void ze::Transform::setWidth(const float width) {
    size.x = width;
}


void ze::Transform::setHeight(const float height) {
    size.y = height;
}


float ze::Transform::centerX() const {
    return pos.x + size.x / 2;
}


float ze::Transform::centerY() const {
    return pos.y + size.y / 2;
}


void ze::Transform::setCenterX(const float centerX) {
    pos.x = centerX - size.x / 2;
}


void ze::Transform::setCenterY(const float centerY) {
    pos.y = centerY - size.y / 2;
}


sf::Vector2f ze::Transform::center() const {
    return {
        pos.x + size.x / 2,
        pos.y + size.y / 2
    };
}


void ze::Transform::setCenter(const sf::Vector2f center) {
    pos.x = center.x - size.x / 2;
    pos.y = center.y - size.y / 2;
}


void ze::Transform::move(const float dt) {
    pos.x += dt * speed * direction.x;
    pos.y += dt * speed * direction.y;
}


void ze::Transform::move(const sf::Vector2f distance) {
    pos += distance;
}


bool ze::Transform::collide(const ze::Transform& t) const {
    return (
        t.right() < size.x || 
        t.left() > right() || 
        t.bottom() < size.y ||
        t.top() > bottom()
    );
}


bool ze::Transform::collideWithShrink(ze::Transform& t) {
    const sf::Vector2f oldSizeThis = size;
    const sf::Vector2f oldSizeOther = t.size;

    size.x *= boxCollideScale.x;
    size.y *= boxCollideScale.y;
    t.size.x *= t.boxCollideScale.x;
    t.size.y *= t.boxCollideScale.y;

    bool collide = (
        t.right() < size.x || 
        t.left() > right() || 
        t.bottom() < size.y ||
        t.top() > bottom()
    );

    size = oldSizeThis;
    t.size = oldSizeOther;

    return collide;

}