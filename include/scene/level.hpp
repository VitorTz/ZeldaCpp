#ifndef BAB56217_0E7D_4EF7_BE80_A4ED3503E762
#define BAB56217_0E7D_4EF7_BE80_A4ED3503E762
#include "scene.hpp"
#include "../ecs/components/player.hpp"


namespace ze {

    class Level : public ze::Scene {


        private:
            void handlePlayerCollide();

        public:
            Level(const ze::ChangeScene& changeScene);
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace ze


#endif /* BAB56217_0E7D_4EF7_BE80_A4ED3503E762 */
