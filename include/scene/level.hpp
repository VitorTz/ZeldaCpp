#ifndef BAB56217_0E7D_4EF7_BE80_A4ED3503E762
#define BAB56217_0E7D_4EF7_BE80_A4ED3503E762
#include "scene.hpp"
#include "../ecs/components/sprite.hpp"
#include "../util/util.hpp"
#include "../constants.hpp"


namespace og {

    class Level : public og::Scene {


        public:
            Level(const og::ChangeScene& changeScene);
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace og


#endif /* BAB56217_0E7D_4EF7_BE80_A4ED3503E762 */
