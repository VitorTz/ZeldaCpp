#ifndef DE98B4F4_7FC8_41D4_A692_16063F161973
#define DE98B4F4_7FC8_41D4_A692_16063F161973
#include "../ecs.hpp"
#include "SpriteAnimation.hpp"
#include "PlayerMovement.hpp"


namespace ze {


    class Player : public ze::Component {

        private:
            ze::SpriteAnimation animation = ze::SpriteAnimation("res/graphics/player/down_moving");
            ze::PlayerMovement movement;

        public:
            Player() : ze::Component("Player") { }
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* obj) override;


    };
    
} // namespace ze


#endif /* DE98B4F4_7FC8_41D4_A692_16063F161973 */
