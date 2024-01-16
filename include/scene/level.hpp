#ifndef F2B5C230_EC93_44FA_91EC_2ADAF7510D9A
#define F2B5C230_EC93_44FA_91EC_2ADAF7510D9A
#include "scene.hpp"
#include "../ecs/components/player.hpp"
#include "../ecs/components/tree.hpp"
#include "../util/util.hpp"


namespace ze {


    class Level : public ze::Scene {

        private:
            std::shared_ptr<ze::GameObj> player;

        public:
            explicit Level(const ze::ChangeScene& changeScene);
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;


    };
    
} // namespace ze


#endif /* F2B5C230_EC93_44FA_91EC_2ADAF7510D9A */
