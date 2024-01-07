#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include "sprite.hpp"
#include "../util/rect.hpp"


namespace ze {


    namespace ougi {

        class Mask {

            private:
                sf::Sprite* sprite;                
                sf::Texture* texture;

            public:                
                Mask(
                    ze::ougi::Sprite* sprite,
                    const sf::Color& color
                );
                Mask(
                    sf::Texture* texture,
                    const sf::Color& color
                );
                ~Mask();
                void draw(
                    sf::RenderWindow& window, 
                    const ze::Rect& rect
                );

        };
        
    } // namespace ougi
    
    
} // namespace ze
