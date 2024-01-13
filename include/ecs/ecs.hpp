#ifndef BEB259A6_6A73_4834_91D2_183EA9B21081
#define BEB259A6_6A73_4834_91D2_183EA9B21081
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "../util/texture_pool.hpp"
#include "../util/transform.hpp"
#include "../constants.hpp"



namespace ze {

    class Component;
    class GameObj;

    class GameObj {

        private:
            std::map<std::string, std::unique_ptr<ze::Component>> componentMap;
        
        public:
            const std::string name;
            ze::Transform transform;
        
        public:
            GameObj(std::string&& name);
            GameObj(std::string&& name, ze::Transform&& transform);
            ~GameObj();            
            void addComponent(ze::Component* c);
            void rmvComponent(const std::string& name);
            ze::Component* getComponent(const std::string& name);
            void update(const float& dt);
            void draw(sf::RenderWindow& window);

    };

    
    class Component {

        public:
            const std::string name;
        
        protected:
            ze::GameObj* gameObj;
        
        public:

            Component(const std::string& name);
            virtual ~Component();
            virtual void update(const float& dt);
            virtual void draw(sf::RenderWindow& window);
            virtual void setGameObj(ze::GameObj* gameObj);
    };
    
} // namespace ze





#endif /* BEB259A6_6A73_4834_91D2_183EA9B21081 */
