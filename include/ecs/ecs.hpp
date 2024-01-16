#ifndef BEB259A6_6A73_4834_91D2_183EA9B21081
#define BEB259A6_6A73_4834_91D2_183EA9B21081
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "../util/transform.hpp"
#include "../util/game_obj_state.hpp"
#include "../util/game_obj_stats.hpp"


namespace ze {

    class Component;
    class GameObj;

    class GameObj {

        private:
            std::map<std::string, std::unique_ptr<ze::Component>> componentMap;
            std::set<std::string> groupName;
        
        public:
            const std::string name;
            ze::Transform transform;
            ze::GameObjState state;
            ze::GameObjStats stats;
        
        public:
            GameObj(GameObj&&) = default;      
            ~GameObj();      
            GameObj(const std::string& name, const ze::Zindex zIndex);
            GameObj(const std::string& name, const ze::Transform& transform);
            void addComponent(ze::Component* c);            
            void rmvComponent(const std::string& name);
            ze::Component* getComponent(const std::string& name);
            void update(const float dt);
            void draw(sf::RenderWindow& window);
            void applyDamage(const float damage);
            void addGroup(const std::string& name);
            const std::set<std::string>& getGroups() const;

    };

    
    class Component {

        public:
            const std::string name;
        
        protected:
            ze::GameObj* gameObj;
        
        public:
            Component(Component&& ) = default;
            explicit Component(const std::string& name);
            virtual ~Component();
            virtual void update(const float dt);
            virtual void draw(sf::RenderWindow& window);
            virtual void setGameObj(ze::GameObj* gameObj);
    };
    
} // namespace ze





#endif /* BEB259A6_6A73_4834_91D2_183EA9B21081 */
