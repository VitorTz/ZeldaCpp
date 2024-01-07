#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../util/texture_pool.hpp"
#include "../util/util.hpp"
#include "../util/rect.hpp"
#include "../constants.hpp"


namespace ze {


    namespace ougi {

        class Sprite {

            private:
                const std::string imagePath;
                sf::Sprite sprite;
            
            protected:
                ze::Rect rect;

            public:
                Sprite();
                Sprite(const std::string& imagePath);
                Sprite(
                    const std::string& imagePath,
                    const ze::Rect& rect
                );
                virtual ~Sprite();
                virtual void update(const float& dt);
                virtual void draw(sf::RenderWindow& window);
                virtual void draw(sf::RenderWindow& window, const ze::Rect& rect);
                sf::Texture* getTexture();
                ze::Rect* getRect();

        };
        
    } // namespace ougi
    
    
} // namespace ze
