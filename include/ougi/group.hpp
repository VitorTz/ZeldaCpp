#pragma once
#include <unordered_set>
#include <string>
#include "sprite.hpp"


namespace ze {

    namespace ougi {

        class Group {

            public:
                const std::string name;

            private:
                std::unordered_set<ze::ougi::Sprite*> sprites;

            public:                
                Group(const std::string& name);
                ~Group();
                void add(ze::ougi::Sprite* sprite);
                void rmv(ze::ougi::Sprite* sprite);
                bool has(ze::ougi::Sprite* sprite) const;
                void update(const float& dt);
                void draw(sf::RenderWindow& window);
                bool empty() const;
                void clear();
                std::unordered_set<ze::ougi::Sprite*>& getSprites();

        };
        
    } // namespace ougi
    
    
} // namespace ze
