#include "../../../include/ecs/components/AnimationPool.hpp"


ze::AnimationPool::AnimationPool(
    const std::vector<ze::AnimationId>& animations
) : ze::Component("AnimationPool") {
    for (const ze::AnimationId id : animations) {
        this->animationMap.insert({id, ze::Animation(id)});
    }
    this->currentAnimation = animations[0];
}


void ze::AnimationPool::update(const float dt) {
    this->animationMap.at(this->currentAnimation).update(dt);
}


void ze::AnimationPool::draw(sf::RenderWindow& window) {
    this->animationMap.at(this->currentAnimation).draw(window);
}


void ze::AnimationPool::setGameObj(ze::GameObj* gameObj) {
    for (auto& [id, animation] : this->animationMap) {
        animation.setGameObj(gameObj);
    }
}


void ze::AnimationPool::insert(const ze::AnimationId id) {
    this->animationMap.insert({id, ze::Animation(id)});
}


void ze::AnimationPool::changeAnimation(const ze::AnimationId id) {
    this->currentAnimation = id;
}


ze::Animation* ze::AnimationPool::getCurrentAnimation() {
    return &this->animationMap.at(this->currentAnimation);
}