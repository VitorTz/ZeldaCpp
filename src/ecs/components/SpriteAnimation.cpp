#include "../../../include/ecs/components/SpriteAnimation.hpp"


ze::SpriteAnimation::SpriteAnimation(
    const std::filesystem::path& source
) : ze::Component("SpriteAnimation-" + source.string()) {
    for (const auto& p : std::filesystem::directory_iterator(source)) {
        this->sprites.push_back(std::make_unique<ze::Sprite>(p.path()));    
    }
    std::sort(
        this->sprites.begin(), this->sprites.end(), 
        [](const std::unique_ptr<ze::Sprite>& s1, const std::unique_ptr<ze::Sprite>& s2) {
            return s1->name < s2->name;
        }
    );
}


void ze::SpriteAnimation::setGameObj(ze::GameObj* obj) {
    ze::Component::setGameObj(obj);
    for (const std::unique_ptr<ze::Sprite>& sprite : this->sprites) {
        sprite->setGameObj(obj);
    }
}