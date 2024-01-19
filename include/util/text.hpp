#ifndef D3259FF5_8F73_4C1B_96CC_60DA7710D694
#define D3259FF5_8F73_4C1B_96CC_60DA7710D694
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include "transform.hpp"


namespace ze {

    class Text {

        public:
            static void draw(
                sf::RenderWindow& window,
                const std::string& txt,
                std::size_t size,
                const sf::Vector2f& pos,
                const sf::Color& color
            );

        private:
            sf::Text text;
            sf::Font font;

        public:
            ze::Transform transform;
        
        public:
            Text(
                const std::string& txt,
                const std::size_t size,                
                const sf::Color& color
            );
            void draw(sf::RenderWindow& window);
    };
    
} // namespace ze


#endif /* D3259FF5_8F73_4C1B_96CC_60DA7710D694 */
