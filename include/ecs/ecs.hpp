#ifndef C6E3A4AC_1ADA_4C9B_98CF_28755F92945A
#define C6E3A4AC_1ADA_4C9B_98CF_28755F92945A
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "../util/transform.hpp"


namespace og {


    class GameObj;

    class Component {

        protected:
            og::GameObj* gameObj;

        public:
            const std::string name;
        
        public:
            Component(Component&& ) = default;
            explicit Component(const std::string& name);
            virtual ~Component();
            virtual void update(const float dt);
            virtual void draw(sf::RenderWindow& window);
            virtual void setGameObj(og::GameObj* gameObj);
                    
    };


    class GameObj {

        public:
            const std::string name;
            og::Transform transform;

        private:
            std::map<std::string, std::unique_ptr<og::Component>> componentMap;
            std::set<std::string> groups;

        public:
            GameObj(GameObj&& ) = default;
            GameObj(const std::string& name, const og::Zindex zIndex);
            GameObj(const std::string& name, const og::Transform& transform);
            ~GameObj();
            void update(const float dt);
            void draw(sf::RenderWindow& window);
            void addComponent(std::unique_ptr<og::Component> component);
            void addGroup(const std::string& name);
            const std::set<std::string>& getGroups() const;
    };
    
    
} // namespace ogg


#endif /* C6E3A4AC_1ADA_4C9B_98CF_28755F92945A */
