#ifndef F4D1D92D_F79E_48A8_B448_AFC6726F79AA
#define F4D1D92D_F79E_48A8_B448_AFC6726F79AA
#include <iostream>
#include "Scene.hpp"
#include "../ecs/GameObjPool.hpp"
#include "../window/Camera.hpp"
#include "../util/util.hpp"


namespace ze {

    
    class Level : public ze::Scene {

        private:
            std::unique_ptr<ze::GameObjPool> gameObjPool = std::make_unique<ze::GameObjPool>();

        private:
            void handleCollide();

        public:
            Level(const ze::ChangeScene& changeScene);
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;

    };

    
} // namespace ze 


#endif /* F4D1D92D_F79E_48A8_B448_AFC6726F79AA */
