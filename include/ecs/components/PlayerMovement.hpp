#ifndef DAEEA290_917C_49FE_8361_933640213CFE
#define DAEEA290_917C_49FE_8361_933640213CFE
#include "../ecs.hpp"
#include "../../util/util.hpp"
#include "../../util/Direction.hpp"
#include "../../constants.hpp"


namespace ze {


    class PlayerMovement : public ze::Component {

        private:
            sf::Vector2f directionVec;
            ze::Direction direction = ze::Direction::Idle;
            bool isMoving_ = false;

        public:
            PlayerMovement() : ze::Component("PlayerMovement") { }
            void update(float dt) override;
            inline void setGameObj(ze::GameObj* gameObj) override {
                ze::Component::setGameObj(gameObj);
                this->gameObj->speed = ze::PLAYER_SPEED;
            }
            inline bool isMoving() { return isMoving_; }

    };
    
} // namespace ze


#endif /* DAEEA290_917C_49FE_8361_933640213CFE */
