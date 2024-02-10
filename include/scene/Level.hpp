#pragma once
#include "Scene.hpp"


namespace ze {

    class Level : public Scene {

        public:
            Level(const ze::ChangeScene& changeScene);
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace ze
