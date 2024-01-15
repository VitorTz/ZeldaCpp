#ifndef FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C
#define FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C
#include <functional>
#include <vector>
#include "../ecs/ecs.hpp"
#include "../util/group/camera.hpp"
#include "../util/group/game_obj_group.hpp"


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
            std::map<std::string, std::unique_ptr<ze::Group>> groups;            
        
        public:
            Scene(const ze::SceneId id, const ze::ChangeScene& changeScene);
            virtual ~Scene();
            virtual void update(const float dt);
            virtual void draw(sf::RenderWindow& window);
            void addToGroup(const std::shared_ptr<ze::GameObj>& obj, const std::vector<std::string>& groups);
    };
    
} // namespace ze


#endif /* FAC1EE2A_4802_4F7D_BFC2_CB8BE2AB5D0C */
