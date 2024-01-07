#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>
#include <string>
#include "../ougi/ougi.hpp"



namespace ze {

    enum class SceneId {
        LevelId
    };

    const ze::SceneId mainScene = ze::SceneId::LevelId;

    typedef std::function<void(const ze::SceneId&)> ChangeScene;

    class Scene {

        public:
            const ze::SceneId id;

        protected:
            ze::ougi::Camera camera;
            const ze::ChangeScene& changeScene;

        public:
            Scene(const ze::SceneId& id, const ze::ChangeScene& changeScene);
            virtual ~Scene();
            virtual void update(const float& dt);
            virtual void draw(sf::RenderWindow& window);

    };
    
} // namespace ze
