//
// Created by vitor on 1/28/24.
//

#ifndef ZELDACPP_SCENE_H
#define ZELDACPP_SCENE_H
#include <SFML/Graphics.hpp>
#include <functional>
#include "../ecs/ecs.h"
#include "../ecs/components.h"


namespace ze {

    enum SceneId {
        LevelId
    };

    typedef std::function<void(SceneId)> ChangeScene;

    const SceneId mainScene = ze::SceneId::LevelId;

    class Scene {

    public:
        const SceneId id;

    protected:
        const ze::ChangeScene& changeScene;

    public:
        Scene(
                SceneId id,
                const ChangeScene& changeScene
        ) : id(id), changeScene(changeScene) { }
        virtual ~Scene() = default;
        virtual void update([[maybe_unused]] float dt) { };
        virtual void render([[maybe_unused]] sf::RenderWindow& window) { };

    };


}

#endif //ZELDACPP_SCENE_H
