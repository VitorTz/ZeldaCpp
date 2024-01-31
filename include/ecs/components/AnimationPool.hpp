#ifndef F2C3EA29_CC1A_4547_8E66_ED5404217D46
#define F2C3EA29_CC1A_4547_8E66_ED5404217D46
#include "Animation.hpp"


namespace ze {


    class AnimationPool : public ze::Component {
        
        private:
            std::map<ze::AnimationId, ze::Animation> animationMap;
            ze::AnimationId currentAnimation;

        public:            
            explicit AnimationPool(const std::vector<ze::AnimationId>& animations);
            void insert(ze::AnimationId id);
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;
            void changeAnimation(ze::AnimationId id);
            ze::Animation* getCurrentAnimation();

    };
    
} // namespace ze


#endif /* F2C3EA29_CC1A_4547_8E66_ED5404217D46 */
