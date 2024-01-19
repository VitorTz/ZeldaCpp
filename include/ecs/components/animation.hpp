#ifndef B816A5BE_F3BB_4BE0_BC58_4479A9E033E5
#define B816A5BE_F3BB_4BE0_BC58_4479A9E033E5
#include <filesystem>
#include <vector>
#include <cmath>
#include "../ecs.hpp"
#include "sprite.hpp"


namespace ze {


    enum AnimationId {
        PlayerAnimationId
    };

    const std::map<ze::AnimationId, std::filesystem::path> animationPathById = {
        {ze::AnimationId::PlayerAnimationId, "res/graphics/player"}
    };


    class Animation : public ze::Component {

        private:            
            float speed;
            float currentFrame;
            std::vector<std::unique_ptr<ze::Sprite>> sprites;

        public:
            Animation(Animation&& ) = default;
            explicit Animation(const std::filesystem::path& path);
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* obj) override;
            void reset();

    };


    class AnimationHandler : public ze::Component {

        private:
            std::map<std::string, std::unique_ptr<ze::Animation>> animationMap;
            std::string currentAnimation;

        public:
            AnimationHandler(const ze::AnimationId id);
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;
            void change(const std::string& animationName);            
            void setGameObj(ze::GameObj* obj) override;
    };
    
} // namespace ze


#endif /* B816A5BE_F3BB_4BE0_BC58_4479A9E033E5 */
