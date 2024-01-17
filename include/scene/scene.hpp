#ifndef DFEEE5BE_E422_4817_98DD_76B35DB694A1
#define DFEEE5BE_E422_4817_98DD_76B35DB694A1
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>
#include <set>
#include "../ecs/ecs.hpp"
#include "../ecs/game_obj_pool.hpp"
#include "../group/group.hpp"
#include "../group/camera.hpp"


namespace og {

    enum SceneId {
        LevelId
    };
    
    const og::SceneId mainScene = og::SceneId::LevelId;

    typedef std::function<void(const og::SceneId)> ChangeScene;

    class Scene {
        
        private:
            std::map<std::string, std::unique_ptr<og::Group>> groups;
            
        public:
            const og::SceneId id;

        protected:

            const og::ChangeScene& changeScene;
            std::unique_ptr<og::GameObjPool> allObjs;
            og::Camera* cameraGroup;
            og::Group* collideGroup;

        protected:
            void addGroup(std::unique_ptr<og::Group> group);
            og::Group* getGroup(const std::string& gName);
            void addObjToGroups(
                std::unique_ptr<og::GameObj>& obj, 
                const std::vector<std::string>& groups
            );
            void rmvObjFromGroups(og::GameObj* obj);
            void rmvAllObjsFromGroup(const std::string& groupName);

        public:
            Scene(
                const og::SceneId id, 
                const og::ChangeScene& changeScene
            );
            virtual ~Scene();
            virtual void update(const float dt);
            virtual void draw(sf::RenderWindow& window);

    };
    
} // namespace og


#endif /* DFEEE5BE_E422_4817_98DD_76B35DB694A1 */
