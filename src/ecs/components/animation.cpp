#include "../../../include/ecs/components/animation.hpp"


ze::Animation::Animation(
    const std::filesystem::path& path
) : ze::Component(path.stem().string()),
    speed(ze::ANIMATION_SPEED),
    currentFrame(0) {
    std::set<std::filesystem::path> files;
    for (const auto& p : std::filesystem::directory_iterator(path)) {
        files.insert(p.path());
    }
    for (const std::filesystem::path& path : files) {
        this->sprites.push_back(std::make_unique<ze::Sprite>(path));
    }
}


void ze::Animation::update(const float dt) {
    this->currentFrame = std::fmod(
        (this->currentFrame + dt * this->speed), 
        this->sprites.size()
    );
}


void ze::Animation::draw(sf::RenderWindow& window) {
    if (!this->sprites.empty()) {
        this->sprites[static_cast<unsigned int>(this->currentFrame)]->draw(window);
    }
}


void ze::Animation::reset() {
    this->currentFrame = 0.f;
}


void ze::Animation::setGameObj(ze::GameObj* obj) {
    ze::Component::setGameObj(obj);
    for (std::unique_ptr<ze::Sprite>& sprite : this->sprites) 
        sprite->setGameObj(obj);
}



ze::AnimationHandler::AnimationHandler(
    const ze::AnimationId id
) : ze::Component("AnimationHandler") {
    for (const auto& p : std::filesystem::directory_iterator(ze::animationPathById.at(id))) {
        this->animationMap.insert(
            {
                p.path().stem().string(), 
                std::make_unique<ze::Animation>(p.path())
            }
        );
    }
}


void ze::AnimationHandler::update(const float dt) {
    this->animationMap.at(this->currentAnimation)->update(dt);
}


void ze::AnimationHandler::draw(sf::RenderWindow& window) {
    this->animationMap.at(this->currentAnimation)->draw(window);
}


void ze::AnimationHandler::change(const std::string& name) {
    this->currentAnimation = name != this->currentAnimation ? name : this->currentAnimation;
}


void ze::AnimationHandler::setGameObj(ze::GameObj* obj) {
    for (const auto& [animationName, animation] : this->animationMap) 
        animation->setGameObj(obj);
}