#ifndef A5307EEF_5A69_477E_81F1_8FF70364286B
#define A5307EEF_5A69_477E_81F1_8FF70364286B
#include "Scene.hpp"
#include "../ecs/GameObjPool.hpp"
#include "../ecs/components.hpp"


namespace ze {


    class Level : public Scene {

        private:
            ze::GameObjPool gameObjPool;

        public:
            Level(const ChangeScene& changeScene);
            void update(float dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace st


#endif /* A5307EEF_5A69_477E_81F1_8FF70364286B */
