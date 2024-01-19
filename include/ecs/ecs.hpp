#ifndef AA071771_769F_4AEC_8CC3_39224B18415A
#define AA071771_769F_4AEC_8CC3_39224B18415A
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <set>
#include "../util/transform.hpp"
#include "../constants.hpp"
#include "../util/util.hpp"
#include "../util/game_obj_state.hpp"
#include "../util/direction.hpp"
#include "../util/map_obj.hpp"


namespace ze {

    class GameObj;

    class Group {

        protected:
            std::set<ze::GameObj*> objs;

        public:
            Group();
            virtual void add(ze::GameObj* obj);
            virtual void rmv(ze::GameObj* obj);
            virtual void clear();            
            virtual std::size_t size() const;
            std::set<ze::GameObj*>* getObjs();
        
    };


    class Component {

        protected:
            ze::GameObj* gameObj;

        public:
            const std::string name;
        
        public:
            Component(Component&& ) = default;
            explicit Component(const std::string& name);
            virtual ~Component();
            virtual void update(const float dt);
            virtual void draw(sf::RenderWindow& window);
            virtual void setGameObj(ze::GameObj* gameObj);
                    
    };


    class GameObj {

        public:
            const std::string name;
            ze::Transform transform;
            ze::GameObjState state;
            ze::Direction direction;

        private:
            std::map<std::string, std::unique_ptr<ze::Component>> componentMap;
            std::set<ze::Group*> groups;

        public:
            GameObj(GameObj&& ) = default;
            GameObj(
                const std::string& name, 
                const ze::Zindex zIndex,
                const std::set<ze::Group*>& groups
            );
            ~GameObj();
            void update(const float dt);
            void draw(sf::RenderWindow& window);
            
            void addComponent(std::unique_ptr<ze::Component> component);
            ze::Component* getComponent(const std::string& componentName);            
            void addToGroup(ze::Group* group);
            void addToGroups(const std::set<ze::Group*>& groups);
            void rmvFromGroup(ze::Group* group);
            void rmvFromAllGroups();            

    };

    class GameObjPool {

        private:
            std::map<std::string, std::unique_ptr<ze::GameObj>> objMap;
            std::map<std::string, std::unique_ptr<ze::Group>> groupMap;
        
        private:
            std::set<ze::Group*> getGroupsByName(const std::vector<std::string>& groups);

        public:
            GameObjPool();
            ~GameObjPool();
            void update(const float dt);            
            
            ze::GameObj* createObj(
                const std::string& objName, 
                const ze::Zindex index,
                const std::vector<std::string>& groups
            );
            void deleteObj(ze::GameObj* obj);
            void deleteObj(const std::string& objName);
            ze::GameObj* getObj(const std::string& objName);
        
            void createGroup(const std::string& groupName);
            void createGroups(const std::vector<std::string>& groups);
            void createGroup(const std::string& groupName, std::unique_ptr<ze::Group> group);
            ze::Group* getGroup(const std::string& groupName);
            const std::map<std::string, std::unique_ptr<ze::Group>>* getGroups();
            std::size_t size() const;
        
    };

} // namespace ze



#endif /* AA071771_769F_4AEC_8CC3_39224B18415A */
