#ifndef FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C
#define FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C
#include <SFML/Graphics.hpp>
#include <functional>
#include "../ecs/ecs.hpp"
#include "../ecs/components/components.hpp"


namespace ze {

    enum SceneId {
        LevelId
    };

    typedef std::function<void(const ze::SceneId&)> ChangeScene;

    const ze::SceneId mainScene = ze::SceneId::LevelId;

    class Scene {

        public:
            const ze::SceneId id;
        
        protected:
            const ze::ChangeScene& changeScene;
            std::map<std::string, std::unique_ptr<ze::GameObj>> gameObjMap;
        
        protected:            
            void addGameObj(std::unique_ptr<ze::GameObj>& gameObj);
            ze::GameObj* getGameObj(const std::string& n);
            void rmvGameObj(const std::string& n);
        
        public:
            Scene(const ze::SceneId& id, const ze::ChangeScene& changeScene);
            virtual ~Scene();
            virtual void update(const float& dt);
            virtual void draw(sf::RenderWindow& window);

    };
    
} // namespace ze


#endif /* FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C */
