#ifndef A48CED4B_BB97_4365_AF97_4156BBA77CDC
#define A48CED4B_BB97_4365_AF97_4156BBA77CDC
#include <SFML/Graphics.hpp>
#include <functional>
#include "../ecs/components.hpp"


namespace ze {


    enum SceneId {
        LevelId
    };


    typedef std::function<void(SceneId)> ChangeScene;

    const SceneId mainScene = SceneId::LevelId;

    class Scene {

        public:
            const SceneId id;

        protected:
            const ChangeScene& changeScene;

        public:
            Scene(SceneId id, const ChangeScene& changeScene) : id(id), changeScene(changeScene) { }
            virtual ~Scene() = default;
            virtual void update(float dt) = 0;
            virtual void draw(sf::RenderWindow& window) = 0;

    };

    
} // namespace ze



#endif /* A48CED4B_BB97_4365_AF97_4156BBA77CDC */
