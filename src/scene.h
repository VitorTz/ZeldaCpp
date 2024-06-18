#ifndef ZELDA_SCENE_H
#define ZELDA_SCENE_H
#include <functional>
#include <raylib.h>
#include "texture_pool.h"
#include "constants.h"
#include "globals.h"


namespace ze {

    enum SceneId {
        TitleScreenId,
        LevelSceneId
    };

    typedef std::function<void(ze::SceneId)> ChangeSceneRequest;

    class Scene {

        public:
            virtual ~Scene() = default;
            virtual void update(const ze::ChangeSceneRequest& change_scene_request) = 0;
            virtual void draw() = 0;

    };


    class TitleScreen : public ze::Scene {

        private:
            Texture2D logo;            
            Texture2D backgroundSprite[2];
            Vector2 backgroundPos[2];            

        public:
            TitleScreen();
            void update(const ze::ChangeSceneRequest& change_scene_request) override;
            void draw() override;

    };


    class LevelScene : public ze::Scene {

        public:
            LevelScene();
            void update(const ze::ChangeSceneRequest& change_scene_request) override;
            void draw() override;
    };
    
} // namespace ze



#endif