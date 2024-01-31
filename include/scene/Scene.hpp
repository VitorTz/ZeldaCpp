#ifndef F9ECA34D_BE48_43DD_9FF6_FBBE2170DA5A
#define F9ECA34D_BE48_43DD_9FF6_FBBE2170DA5A
#include <SFML/Graphics.hpp>
#include <functional>


namespace ze {

    enum SceneId {
        LevelSceneId
    };

    const SceneId mainScene = SceneId::LevelSceneId;

    typedef std::function<void(SceneId)> ChangeScene;

    class Scene {

        public:
            const SceneId id;

        protected:
            const ChangeScene& changeScene;

        public:
            Scene(SceneId id, const ChangeScene& changeScene) : id(id), changeScene(changeScene) { }
            virtual ~Scene() = default;
            virtual void update([[maybe_unused]] float dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }

    };
    
} // namespace st



#endif /* F9ECA34D_BE48_43DD_9FF6_FBBE2170DA5A */
