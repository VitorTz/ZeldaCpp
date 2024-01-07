#pragma once
#include <map>
#include "group.hpp"


namespace ze {


    namespace ougi {

        class Camera {

            private:
                std::map<int, ze::ougi::Group*> groups;

            public:
                Camera();
                ~Camera();
                void createGroup(const int& zIndex);
                ze::ougi::Group* getGroup(const int& zIndex);
                void update(const float& dt);
                void draw(sf::RenderWindow& window);
                std::map<int, ze::ougi::Group*>& getGroups();

        };
        
    } // namespace ougi
    
    
} // namespace ze
