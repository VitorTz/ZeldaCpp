#ifndef F2B5C230_EC93_44FA_91EC_2ADAF7510D9A
#define F2B5C230_EC93_44FA_91EC_2ADAF7510D9A
#include "scene.hpp"
#include "../ecs/components/player.hpp"


namespace ze {


    class Level : public ze::Scene {

        private:
            std::shared_ptr<ze::GameObj> player;

        public:
            explicit Level(const ze::ChangeScene& changeScene);
            void update(const float dt) override;


    };
    
} // namespace ze


#endif /* F2B5C230_EC93_44FA_91EC_2ADAF7510D9A */
