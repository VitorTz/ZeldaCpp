#ifndef FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C
#define FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C
#include <functional>
#include <vector>
#include "../ecs/ecs.hpp"
#include "../util/group/camera.hpp"


namespace ze {

    enum SceneId {
        LevelId
    };

    typedef std::function<void(const ze::SceneId)> ChangeScene;

    const ze::SceneId mainScene = ze::SceneId::LevelId;

    class Scene {

        public:
            const ze::SceneId id;
        
        protected:
            const ze::ChangeScene& changeScene;
            ze::Camera* camera;
            ze::Group* allObjsGroup;
            ze::Group* collideGroup;
            std::map<std::string, std::unique_ptr<ze::Group>> groups;            
        
        protected:
            void rmvAllFromGroup(const std::string& groupName);
            void rmvObj(const std::shared_ptr<ze::GameObj>& obj);
            void addGroup(ze::Group* group);
            void addObj(
                const std::shared_ptr<ze::GameObj>& obj, 
                const std::vector<std::string>& groups
            );

        public:
            Scene(
                const ze::SceneId id, 
                const ze::ChangeScene& changeScene
            );
            virtual ~Scene();
            virtual void update(const float dt);
            virtual void draw(sf::RenderWindow& window);
    };
    
} // namespace ze


#endif /* FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C */
