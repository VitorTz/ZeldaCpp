#include "../../include/ougi/animation.hpp"
#include <iostream>



ze::ougi::Animation::Animation(
    const ze::ougi::AnimationId& animationId
) : animationId(animationId) {
    std::filesystem::path p(ze::ougi::spriteDirByAnimation.at(animationId));
    std::vector<std::string> files;
    for (const auto& dir : std::filesystem::directory_iterator(p))
        files.push_back(dir.path().string());
    std::sort(files.begin(), files.end());

    for (const std::string& s : files)
        this->sprites.push_back(new ze::ougi::Sprite(s));

}


ze::ougi::Animation::~Animation() {
    for (ze::ougi::Sprite* s : this->sprites)
        delete s;
    this->sprites.clear();
}


void ze::ougi::Animation::update(const float& dt) {
    const float delta = dt * ze::ougi::ANIMATION_SPEED;
    this->currentSpriteIndex = std::fmod(this->currentSpriteIndex + delta, this->sprites.size());
}


void ze::ougi::Animation::draw(
    sf::RenderWindow& window,
    const ze::Rect& rect
) {
    ze::ougi::Sprite* s = this->sprites.at((int) this->currentSpriteIndex);
    s->draw(window, rect);
}


void ze::ougi::Animation::reset() {
    this->currentSpriteIndex = 0;
}


ze::ougi::AnimationGroup::AnimationGroup(
    const std::vector<ze::ougi::AnimationId>& animations
) : animationId(animations[0]) {
    for (const ze::ougi::AnimationId& id : animations)
        this->add(id);        
}


ze::ougi::AnimationGroup::~AnimationGroup() {
    for (const auto& pair : this->animations) 
        delete pair.second;
    this->animations.clear();
}


void ze::ougi::AnimationGroup::add(const ze::ougi::AnimationId& animation) {
    this->animations.insert({animation, new ze::ougi::Animation(animation)});
}


void ze::ougi::AnimationGroup::change(const ze::ougi::AnimationId& animation) {
    if (animation != this->animationId) {
        this->animationId = animation;
        this->animations.at(animation)->reset();
    }
}


void ze::ougi::AnimationGroup::update(const float& dt) {
    this->animations.at(this->animationId)->update(dt);
}


void ze::ougi::AnimationGroup::draw(sf::RenderWindow& window, const ze::Rect& rect) {
    this->animations.at(this->animationId)->draw(window, rect);
}


const ze::ougi::AnimationId& ze::ougi::AnimationGroup::getAnimationId() const {
    return this->animationId;
}