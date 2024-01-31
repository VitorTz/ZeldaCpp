#ifndef C05CEE60_0F94_49FE_8FF0_7205807561DC
#define C05CEE60_0F94_49FE_8FF0_7205807561DC
#include <SFML/Graphics.hpp>
#include <memory>
#include <map>
#include <string>
#include "../util/Rect.hpp"
#include "../util/zIndex.hpp"
#include "../util/util.hpp"
#include "../util/GameObjState.hpp"


namespace ze {

    class GameObj;

    class Component {

        protected:
            ze::GameObj* gameObj = nullptr;

        public:
            const std::string name;

        public:
            explicit Component(std::string name_) : name(std::move(name_)) { }
            virtual ~Component() = default;
            virtual void update([[maybe_unused]] const float dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }
            virtual void setGameObj(ze::GameObj* gameObj_) { this->gameObj = gameObj_; }

    };

    class GameObj {

        private:
            std::map<std::string, std::unique_ptr<ze::Component>> componentMap;
            sf::Vector2f lastMovement;
        
        public:

            const std::string name;
            const ze::Zindex zIndex;
            sf::Vector2f direction;
            ze::Rect rect;
            float speed = 0;
            float rotation = 0;
            ze::GameObjState state = ze::GameObjState::DownIdle;
            sf::Vector2f scale = {1.f, 1.f};
            bool isVisible = true;        
        
        public:

            GameObj(std::string name_, ze::Zindex zIndex_) : name(std::move(name_)), zIndex(zIndex_) { } 
            void update(float dt);
            void draw(sf::RenderWindow& window);
            void addComponent(std::unique_ptr<ze::Component> c);
            void move(float dt);
            void undoLastMovement();
            ze::Component* getComponent(const std::string& name);

    };
    
} // namespace ze 


#endif /* C05CEE60_0F94_49FE_8FF0_7205807561DC */
