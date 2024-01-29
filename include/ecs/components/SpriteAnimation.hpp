#ifndef C4502766_A83A_4E59_BF03_1C0BCD5D4D88
#define C4502766_A83A_4E59_BF03_1C0BCD5D4D88
#include "Sprite.hpp"
#include <algorithm>
#include <cmath>
#include <set>


namespace ze {

    enum SpriteAnimationId {
        PlayerAnimationId
    };


    const std::map<ze::SpriteAnimationId, std::filesystem::path> spriteAnimationPathById = {
        {ze::SpriteAnimationId::PlayerAnimationId, "res/graphics/player"}
    };


    const float ANIMATION_SPEED = 7;

    
    class SpriteAnimation : public ze::Component {

        private:
            float currentIndex = 0.f;

        public:
            std::vector<std::unique_ptr<ze::Sprite>> sprites;

        public:
            explicit SpriteAnimation(const std::filesystem::path& source);
            inline void update(float dt) override {
                this->currentIndex = std::fmod(
                    this->currentIndex + dt * ze::ANIMATION_SPEED, 
                    this->sprites.size()
                );
            };
            inline void draw(sf::RenderWindow& window) override { 
                this->sprites[static_cast<int>(this->currentIndex)]->draw(window); 
            };
            inline void reset() { currentIndex = 0.f; };
            void setGameObj(ze::GameObj* gameObj) override;
            
    };
    
} // namespace ze



#endif /* C4502766_A83A_4E59_BF03_1C0BCD5D4D88 */
