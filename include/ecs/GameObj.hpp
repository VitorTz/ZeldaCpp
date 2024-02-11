#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "../util/Transform.hpp"
#include "../util/util.hpp"
#include "../constants.hpp"


namespace ze {


    class GameObj;


    class Component {
        
        public:
            const std::string name;
        
        protected:
            ze::GameObj* gameObj;
        
        public:
            Component(Component&& ) = default;
            Component(
                std::string name_
            ) : name(std::move(name_)), 
                gameObj(nullptr) { }
            virtual ~Component() = default;
            virtual void update([[maybe_unused]] float dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }
            virtual void setGameObj(ze::GameObj* gameObj_) { gameObj = gameObj_; }

    };


    class GameObj {

        public:
            const std::string name;
            const int zIndex;
            ze::Transform transform;
        
        private:
            std::map<std::string, std::unique_ptr<ze::Component>> componentMap;
        
        public:
            GameObj(std::string name_, const int zIndex);
            ~GameObj() = default;
            void addComponent(std::unique_ptr<ze::Component> c);
            ze::Component* getComponent(const std::string& componentName);
            void update(float dt);
            void draw(sf::RenderWindow& window);

    };

    
} // namespace ze
