#include "../../../include/ecs/components/Animation.hpp"


ze::Animation::Animation(
    const ze::AnimationId id 
) : ze::Component("Animation-" + std::to_string((int)id)),
    id(id) {
        for (const auto& p : std::filesystem::directory_iterator(ze::animationDirById.at(id))) {
            this->sprites.push_back(std::make_unique<ze::Sprite>(p.path()));
        }
        std::sort(
            this->sprites.begin(),
            this->sprites.end(),
            [](const std::unique_ptr<ze::Sprite>& s1, const std::unique_ptr<ze::Sprite>& s2) {
                return s1->name < s2->name;
            }
        );
    }


void ze::Animation::update(const float dt) {
    this->currentSprite = std::fmod(
        this->currentSprite * dt * ze::ANIMATION_SPEED,
        this->sprites.size()
    );
}


void ze::Animation::draw(sf::RenderWindow& window) {
    if (!this->sprites.empty()) {
        this->sprites[(int) this->currentSprite]->draw(window);
    }
}


void ze::Animation::setGameObj(ze::GameObj* gameObj) {
    ze::Component::setGameObj(gameObj);
    for (std::unique_ptr<ze::Sprite>& sprite : this->sprites) {
        sprite->setGameObj(gameObj);
    }
}


void ze::Animation::reset() {
    this->currentSprite = 0.f;
}