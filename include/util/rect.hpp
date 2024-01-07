#pragma once
#include <SFML/System/Vector2.hpp>


namespace ze {

    class Rect {

        private:
            sf::Vector2f pos;
            sf::Vector2f size;
        
        public:
            Rect();
            Rect(const sf::Vector2f& pos, const sf::Vector2f& size);
            
            const sf::Vector2f& getPos() const;
            const sf::Vector2f& getSize() const;
            void setSize(const sf::Vector2f& size);
            void setPos(const sf::Vector2f& pos);

            float left() const;
            float right() const;
            float bottom() const;
            float top() const;

            void setLeft(const float& l);
            void setRight(const float& r);
            void setBottom(const float& b);
            void setTop(const float& t);

            void move(const sf::Vector2f& v);
            void move(const float& x, const float& y);

    };
    
} // namespace ze
