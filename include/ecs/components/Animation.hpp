#ifndef F4E98FD5_C9AC_47B7_826F_B5634A4E660A
#define F4E98FD5_C9AC_47B7_826F_B5634A4E660A
#include <filesystem>
#include <algorithm>
#include <vector>
#include "../GameObj.hpp"
#include "Sprite.hpp"


namespace ze {


    enum AnimationId {
        PlayerAnimation
    };


    const std::map<ze::AnimationId, std::filesystem::path> animationDirById = {

    };


    const float ANIMATION_SPEED = 7;

    
    class Animation : public ze::Component {


        private:
            std::vector<std::unique_ptr<ze::Sprite>> sprites;
            float currentSprite = 0.f;
        
        public:
            const ze::AnimationId id;

        public:
            Animation(Animation&& ) = default;
            explicit Animation(AnimationId id);
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;
            void reset();        

    };
    
} // namespace ze


#endif /* F4E98FD5_C9AC_47B7_826F_B5634A4E660A */
