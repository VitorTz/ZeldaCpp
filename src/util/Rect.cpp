//
// Created by vitor on 1/28/24.
//
#include "../../include/util/Rect.h"



void ze::Rect::moveHorizontal(const float x) {
    this->pos.x += x;
}


void ze::Rect::moveVertical(const float y) {
    this->pos.y += y;
}


void ze::Rect::move(sf::Vector2f distance) {
    this->pos += distance;
}


sf::Vector2f ze::Rect::getPos() const {
    return this->pos;
}


sf::Vector2f ze::Rect::getSize() const {
    return this->size;
}



void ze::Rect::setPos(sf::Vector2f pos_) {
    this->pos = pos_;
}


void ze::Rect::setSize(sf::Vector2f size_) {
    this->size = size_;
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


void ze::Rect::setLeft(float left) {
    this->pos.x = left;
}


void ze::Rect::setRight(float right) {
    this->pos.x = right - this->size.x;
}


void ze::Rect::setBottom(float bottom) {
    this->pos.y = bottom - this->size.y;
}


void ze::Rect::setTop(float top) {
    this->pos.y = top;
}


sf::Vector2f ze::Rect::center() const {
    return {this->pos.x + this->size.x / 2, this->pos.y + this->size.y / 2};
}


void ze::Rect::setCenter(sf::Vector2f center) {
    this->pos.x = center.x - this->size.x / 2;
    this->pos.y = center.y - this->size.y / 2;
}


float ze::Rect::centerX() const {
    return this->pos.x + this->size.x / 2;
}


float ze::Rect::centerY() const {
    return this->pos.y + this->size.y / 2;
}


void ze::Rect::setCenterX(float x_) {
    this->pos.x = x_ - this->size.x / 2;
}


void ze::Rect::setCenterY(float y_) {
    this->pos.y = y_ - this->size.y / 2;
}


float ze::Rect::width() const {
    return this->size.x;
}


float ze::Rect::height() const {
    return this->size.y;
}


void ze::Rect::setWidth(float width) {
    this->size.x = width;
}


void ze::Rect::setHeight(float height) {
    this->size.y = height;
}