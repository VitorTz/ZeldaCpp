#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "../ecs/Ecs.hpp"
#include "../ecs/components.hpp"


namespace ze {

    enum SceneId {
        LevelScene
    };

    const ze::SceneId mainScene = ze::SceneId::LevelScene;

    typedef std::function<void(ze::SceneId)> ChangeScene;

    class Scene {

        public:
            const ze::SceneId id;

        protected:
            const ze::ChangeScene& changeScene;
        
        public:
            Scene(
                ze::SceneId id, 
                const ze::ChangeScene& changeScene
            ) : id(id), changeScene(changeScene) { }
            virtual ~Scene() = default;
            virtual void update([[maybe_unused]] float dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }

    };
    
} // namespace ze


