#ifndef C941DF79_A1BE_4829_9B7E_7FE8A1EA43B3
#define C941DF79_A1BE_4829_9B7E_7FE8A1EA43B3
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <map>
#include "../util/Rect.hpp"


namespace ze {


    class GameObj;


    class Component {


        public:
            const std::string name;

        protected:
            ze::GameObj* gameObj;

        public:
            Component(std::string name) : name(std::move(name)), gameObj(nullptr) { }
            virtual ~Component() = default;
            virtual void update([[maybe_unused]] float dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }
            virtual void setGameObj(ze::GameObj* gameObj_) { this->gameObj = gameObj_; }

    };


    class GameObj {

        public:
            const std::string name;
            const int zIndex = 0;
            float speed = 0;
            float rotation = 0;
            float scale = 1.f;
            sf::Vector2f boxCollideScale = {1.f, 1.f};
            sf::Vector2f lastMovement;
            ze::Rect rect;

        private:
            std::map<std::string, std::unique_ptr<ze::Component>> componentMap;
        
        public:
            GameObj(std::string name, int zIndex) : name(std::move(name)), zIndex(zIndex) { }
            ~GameObj() = default;
            void update(float dt);
            void draw(sf::RenderWindow& window);
            void addComponent(std::unique_ptr<ze::Component> c);
            inline void undoLastMovement() { rect.move(-lastMovement); lastMovement = {0.f, 0.f}; }
            inline ze::Component* getComponent(const std::string& componentName) { return this->componentMap.at(componentName).get(); };

    };
    
} // namespace ze



#endif /* C941DF79_A1BE_4829_9B7E_7FE8A1EA43B3 */
