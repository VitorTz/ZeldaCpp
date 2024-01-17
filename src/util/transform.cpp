#include "../../include/util/transform.hpp"


og::Transform::Transform(
    const og::Zindex zIndex
) : shrinkScale(1.f, 1.f),
    zIndex(zIndex) {
    
}


og::Transform::Transform(
    const sf::Vector2f& pos,
    const sf::Vector2f& size,
    const og::Zindex zIndex
) : pos(pos),
    size(size),    
    shrinkScale(1.f, 1.f),
    zIndex(zIndex) {
        
    }


og::Transform::Transform(
    const sf::Vector2f& pos,
    const og::Zindex zIndex
) : pos(pos),    
    shrinkScale(1.f, 1.f),
    zIndex(zIndex) {

    }


float og::Transform::left() const {
    return this->pos.x;
}


float og::Transform::bottom() const {
    return this->pos.y + this->size.y;
}


float og::Transform::top() const {
    return this->pos.y;
}


float og::Transform::right() const {
    return this->pos.x + this->size.x;
}


void og::Transform::setLeft(const float left) {
    this->pos.x = left;
}


void og::Transform::setBottom(const float bottom) {
    this->pos.y = bottom - this->size.y;
}


void og::Transform::setTop(const float top) {
    this->pos.y = top;
}


void og::Transform::setRight(const float right) {
    this->pos.x = right - this->size.x;
}


float og::Transform::centerX() const {
    return this->pos.x + this->size.x / 2;
}


float og::Transform::centerY() const {
    return this->pos.y + this->size.y / 2;
}


void og::Transform::setCenterX(const float x) {
    this->pos.x = x - this->size.x / 2;
}


void og::Transform::setCenterY(const float y) {
    this->pos.y = y - this->size.y / 2;
}


sf::Vector2f og::Transform::center() const {
    return {this->centerX(), this->centerY()};
}


void og::Transform::setCenter(const sf::Vector2f& v) {
    this->setCenterX(v.x);
    this->setCenterY(v.y);
}



sf::Vector2f og::Transform::move(const float& dt) {    
    og::normalizeVector(this->direction);
    sf::Vector2f delta = {
        dt * this->direction.x * this->speed,
        dt * this->direction.y * this->speed
    };
    this->pos.x += delta.x;
    this->pos.y += delta.y;
    return delta;
}


void og::Transform::move(const sf::Vector2f& delta) {
    this->pos.x += delta.x;
    this->pos.y += delta.y;
}


og::Transform og::Transform::shrink() const {
    og::Transform t(this->zIndex);
    t.size = {
        this->size.x * this->shrinkScale.x,
        this->size.y * this->shrinkScale.y
    };
    t.setCenter(this->center());
    return t;
}

bool og::Transform::collide(const og::Transform& t) const {
    og::Transform t1 = this->shrink();
    og::Transform t2 = t.shrink();
    
    if (t2.left() > t1.right() || t2.right() < t1.left()) {
        return false;
    } else if (t2.bottom() < t1.top() || t2.top() > t1.bottom()) {
        return false;
    }
    
    return true;
}


bool og::Transform::collide(const sf::Vector2f& pos, const sf::Vector2f& size) const {
    og::Transform t(pos, size, og::zIndexVector.at(0));
    return this->collide(t);
}


float og::Transform::width() const {
    return this->size.x;
}


float og::Transform::height() const {
    return this->size.y;
}


void og::Transform::setWidth(const float width) {
    this->size.x = width;
}


void og::Transform::setHeight(const float height) {
    this->size.y = height;
}


