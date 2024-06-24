#ifndef ZELDA_SCENE_HPP
#define ZELDA_SCENE_HPP



namespace ze {

    enum SceneId {
        TitleScreenId,
        LevelSceneId
    };


    class Scene {

        public:
            virtual ~Scene() = default;
            virtual void update() = 0;
            virtual void draw() = 0;
        
    };  

    class TitleScreen : public ze::Scene {

        public:
            TitleScreen();
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