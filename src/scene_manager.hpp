#ifndef ZELDA_SCENE_MANAGER_HPP
#define ZELDA_SCENE_MANAGER_HPP
#include "scene.hpp"
#include <memory>

namespace ze {
    

    class SceneManager {

        private:
            std::unique_ptr<ze::Scene> scene;
            bool should_change_scene = false;
            ze::SceneId next_scene;
        
        public:            
            void init();
            void requestChangeScene(ze::SceneId sceneId);
            void update();
            void draw();

    };


    inline ze::SceneManager gSceneManager{};

} // namespace ze



#endif