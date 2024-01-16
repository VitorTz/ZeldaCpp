#ifndef E4778C38_B8C4_400A_8C03_97A8946D706C
#define E4778C38_B8C4_400A_8C03_97A8946D706C
#include "../../util/animation_group.hpp"
#include "../../util/timer.hpp"
#include "../../util/task.hpp"


namespace ze {


    class Player : public ze::Component {

        private:
            ze::AnimationGroup animationGroup;            
            ze::Task attackTask;
            ze::Task damageTask;
            ze::Timer attackSpeedTimer;
            sf::Vector2f lastMove;            
            
        private:
            void handleAttack();
            void handleMovement(const float dt);            
        
        public:
            Player();
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;        
            void undoMovement();
            void applyDamage();
            
    };
    
} // namespace ze


#endif /* E4778C38_B8C4_400A_8C03_97A8946D706C */
