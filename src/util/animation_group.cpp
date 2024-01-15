#include "../../include/util/animation_group.hpp"


ze::AnimationGroup::AnimationGroup(
    const std::vector<std::string>& animations
) : ze::AnimationGroup("AnimationGroup", animations) {

}


ze::AnimationGroup::AnimationGroup(
    const std::string& name,
    const std::vector<std::string>& animations
) : name(name) {
    if (animations.empty()) {
        throw std::out_of_range("Animations vector for" + name + " is empty");
    }
    for (const std::string& s : animations)
        this->addAnimation(s);

    this->currentAnimation = animations.at(0);
}


void ze::AnimationGroup::addAnimation(const std::string& name) {
    this->animationMap.insert(
        {
            name,
            std::make_unique<ze::Animation>(name)
        }
    );
}


void ze::AnimationGroup::change(const std::string& name) {
    if (this->animationMap.find(name) == this->animationMap.end()) {
        throw std::out_of_range("Animation " + name + " not in animation " + this->name);
    }
    if (name != this->currentAnimation) {
        this->currentAnimation = name;
        this->animationMap.at(name)->reset();
    }
}


void ze::AnimationGroup::update(const float dt) {
    std::unique_ptr<ze::Animation>& animation = this->animationMap.at(this->currentAnimation);
    animation->update(dt);
}


void ze::AnimationGroup::draw(sf::RenderWindow& window) {
    std::unique_ptr<ze::Animation>& animation = this->animationMap.at(this->currentAnimation);
    animation->draw(window);
}


void ze::AnimationGroup::setGameObj(ze::GameObj* gameObj) {
    for (const auto& [name, animation] : this->animationMap)
        animation->setGameObj(gameObj);
}


void ze::AnimationGroup::enableMask() {
    for (const auto& [name, animation] : this->animationMap)
        animation->enableMask();
}


void ze::AnimationGroup::disableMask() {
    for (const auto& [name, animation] : this->animationMap)
        animation->disableMask();
}


const std::string& ze::AnimationGroup::getName() const {
    return this->name;
}