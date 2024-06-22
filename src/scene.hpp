#ifndef ZELDA_SCENE_HPP
#define ZELDA_SCENE_HPP
#include <raylib.h>


namespace ze {

    class Scene {

        public:
            virtual ~Scene() = default;
            virtual void update() = 0;
            virtual void draw() = 0;

    };


    class TitleScreenScene : public ze::Scene {

        private:
            Vector2 pos[2];

        public:
            TitleScreenScene();
            void update() override;
            void draw() override;

    };  


    class LevelScene : public ze::Scene {

        public:
            LevelScene();
            void update() override;
            void draw() override;

    };  


    
} // namespace ze



#endif