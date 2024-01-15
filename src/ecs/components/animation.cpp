#include "../../../include/ecs/components/animation.hpp"


ze::Animation::Animation(
    const std::string& name
) : ze::Component(name),
    maskIsEnable(false) {
    
    std::vector<std::string> v;
    for (const auto& p : std::filesystem::directory_iterator(ze::animationPathByName.at(name))) {
        v.push_back(p.path().string());
    }
    std::sort(v.begin(), v.end());

    for (const std::string& s : v) {
        this->spriteList.push_back(
            std::make_unique<ze::Sprite>(
                "sprite",
                ze::ImageSource{s}
            )
        );
        this->maskList.push_back(
            std::make_unique<ze::Sprite>(
                "mask",
                ze::ImageSource{s, true, sf::Color::White}
            )
        );
    }

}


void ze::Animation::enableMask() {
    this->maskIsEnable = true;
}


void ze::Animation::disableMask() {
    this->maskIsEnable = false;
}


void ze::Animation::update(const float dt) {
    if (this->spriteList.empty())
        return;
    this->spriteIndex = std::fmod(
        this->spriteIndex + dt * ze::ANIMATION_SPEED, this->spriteList.size()
    );
}


void ze::Animation::draw(sf::RenderWindow& window) {
    if (this->spriteList.empty())
        return;
    
    auto& l = this->maskIsEnable ? this->maskList : this->spriteList;
    ze::Sprite* s = l.at((unsigned int) this->spriteIndex).get();
    s->draw(window);
}


void ze::Animation::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    
    for (std::unique_ptr<ze::Sprite>& s : this->spriteList)
        s->setGameObj(gameObj);
    
    for (std::unique_ptr<ze::Sprite>& s : this->maskList)
        s->setGameObj(gameObj);
}


void ze::Animation::reset() {
    this->spriteIndex = 0;
}


