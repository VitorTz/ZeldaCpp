#ifndef ZELDA_SCENE_MANAGER_HPP
#define ZELDA_SCENE_MANAGER_HPP
#include <memory>
#include "types.hpp"
#include "scene.hpp"



namespace ze {

    class SceneManager {

        private:
            std::unique_ptr<ze::Scene> scene;
            ze::SceneId nextScene;
            bool shouldChangeScene = false;

        private:
            void loadNextScene();
        
        public:
            SceneManager();
            void changeScene(ze::SceneId scene);
            void update();
            void draw();

    };

    inline ze::SceneManager gSceneManager{};
    
} // namespace ze



#endif