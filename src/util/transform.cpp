#include "../../include/util/transform.hpp"


ze::Transform::Transform(
    const ze::Zindex zIndex
) : scale(1.f, 1.f),
    zIndex(zIndex) {
    
}


ze::Transform::Transform(
    const sf::Vector2f& pos,
    const sf::Vector2f& size,
    const ze::Zindex zIndex
) : pos(pos),
    size(size),
    scale({1.f, 1.f}),
    zIndex(zIndex) {
        
    }


ze::Transform::Transform(
    const sf::Vector2f& pos,
    const ze::Zindex zIndex
) : pos(pos),
    scale(1.f, 1.f),
    zIndex(zIndex) {

    }

ze::Transform::Transform(
    const sf::Vector2f& pos,
    const sf::Vector2f& size,
    const sf::Vector2f& scale,
    const ze::Zindex zIndex
) : pos(pos),
    size(size),
    scale(scale),
    zIndex(zIndex) {

    }



float ze::Transform::left() const {
    return this->pos.x;
}


float ze::Transform::bottom() const {
    return this->pos.y + this->size.y;
}


float ze::Transform::top() const {
    return this->pos.y;
}


float ze::Transform::right() const {
    return this->pos.x + this->size.x;
}


void ze::Transform::setLeft(const float left) {
    this->pos.x = left;
}


void ze::Transform::setBottom(const float bottom) {
    this->pos.y = bottom - this->size.y;
}


void ze::Transform::setTop(const float top) {
    this->pos.y = top;
}


void ze::Transform::setRight(const float right) {
    this->pos.x = right - this->size.x;
}


float ze::Transform::centerX() const {
    return this->pos.x + this->size.x / 2;
}


float ze::Transform::centerY() const {
    return this->pos.y + this->size.y / 2;
}


void ze::Transform::setCenterX(const float x) {
    this->pos.x = x - this->size.x / 2;
}


void ze::Transform::setCenterY(const float y) {
    this->pos.y = y - this->size.y / 2;
}


sf::Vector2f ze::Transform::center() const {
    return {this->centerX(), this->centerY()};
}


void ze::Transform::setCenter(const sf::Vector2f& v) {
    this->setCenterX(v.x);
    this->setCenterY(v.y);
}



void ze::Transform::move(const float& dt) {    
    ze::normalizeVector(this->direction);
    this->pos.x += dt * this->direction.x * this->speed;
    this->pos.y += dt * this->direction.y * this->speed;
}


void ze::Transform::move(const sf::Vector2f& delta) {
    this->pos.x += delta.x;
    this->pos.y += delta.y;
}


bool ze::Transform::collide(const ze::Transform& t) {
    if (t.left() > this->right() || t.right() < this->left())
        return false;
    
    if (t.bottom() < this->top() || t.top() > this->bottom())
        return false;
    return true;
}


float ze::Transform::width() const {
    return this->size.x;
}


float ze::Transform::height() const {
    return this->size.y;
}


void ze::Transform::setWidth(const float width) {
    this->size.x = width;
}


void ze::Transform::setHeight(const float height) {
    this->size.y = height;
}


