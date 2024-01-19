#ifndef C47EA38C_2D22_4BDF_9B63_D9631C7F7D32
#define C47EA38C_2D22_4BDF_9B63_D9631C7F7D32
#include "animation.hpp"


namespace ze {


    class Player : public ze::Component {

        private:
            ze::AnimationHandler animation;
        
        public:
            sf::Vector2f lastMovement;            

        private:
            void move(const float dt);
        
        public:
            Player(Player&& ) = default;
            Player();
            void undoLastMovement();
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* obj) override;

    };
    
} // namespace ze


#endif /* C47EA38C_2D22_4BDF_9B63_D9631C7F7D32 */
