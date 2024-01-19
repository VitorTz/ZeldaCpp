#include "../../include/util/transform.hpp"


ze::Transform::Transform(

) : boxColliderScale(1.f, 1.f),
    zIndex(ze::zIndexVector[0]),
    speed(0) {

    }

ze::Transform::Transform(
    const ze::Zindex zIndex
) : boxColliderScale(1.f, 1.f),
    zIndex(zIndex),
    speed(0) {
    
}


ze::Transform::Transform(
    const sf::Vector2f& pos,
    const sf::Vector2f& size,
    const ze::Zindex zIndex
) : pos(pos),
    size(size),    
    boxColliderScale(1.f, 1.f),
    zIndex(zIndex),
    speed(0) {
        
    }


ze::Transform::Transform(
    const sf::Vector2f& pos,
    const ze::Zindex zIndex
) : pos(pos),    
    boxColliderScale(1.f, 1.f),
    zIndex(zIndex),
    speed(0) {

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


void ze::Transform::setCenterX(const float x_) {
    this->pos.x = x_ - this->size.x / 2;
}


void ze::Transform::setCenterY(const float y_) {
    this->pos.y = y_ - this->size.y / 2;
}


sf::Vector2f ze::Transform::center() const {
    return {this->centerX(), this->centerY()};
}


void ze::Transform::setCenter(const sf::Vector2f& v) {
    this->setCenterX(v.x);
    this->setCenterY(v.y);
}



sf::Vector2f ze::Transform::move(const float& dt) {    
    ze::normalizeVector(this->direction);
    sf::Vector2f delta = {
        dt * this->direction.x * this->speed,
        dt * this->direction.y * this->speed
    };
    this->pos.x += delta.x;
    this->pos.y += delta.y;
    return delta;
}


void ze::Transform::move(const sf::Vector2f& distance) {
    this->pos.x += distance.x;
    this->pos.y += distance.y;
}


ze::Transform ze::Transform::shrink() const {
    ze::Transform t(this->zIndex);
    t.size = {
        this->size.x * this->boxColliderScale.x,
        this->size.y * this->boxColliderScale.y
    };
    t.setCenter(this->center());
    return t;
}

bool ze::Transform::collide(const ze::Transform& t1, const ze::Transform& t2) {
    if (t2.left() > t1.right() || t2.right() < t1.left()) 
        return false;
    else if (t2.bottom() < t1.top() || t2.top() > t1.bottom())
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


