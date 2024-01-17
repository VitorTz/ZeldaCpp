#ifndef MANGA_READER_TRANSFORM_HPP
#define MANGA_READER_TRANSFORM_HPP
#include <SFML/System/Vector2.hpp>
#include "z_index.hpp"


namespace og {

    void normalizeVector(sf::Vector2f& v);

    class Transform {

        public:
            sf::Vector2f pos;
            sf::Vector2f size;
            sf::Vector2f direction;
            sf::Vector2f shrinkScale;
            const og::Zindex zIndex;
            float speed;

        public:
            explicit Transform(const og::Zindex zIndex);
            Transform(
                const sf::Vector2f& pos,
                const og::Zindex zIndex
            );
            Transform(
                const sf::Vector2f& pos,
                const sf::Vector2f& size,                
                const og::Zindex zIndex
            );
            
            float left() const;
            float right() const;
            float bottom() const;
            float top() const;

            void setLeft(const float left);
            void setRight(const float right);
            void setBottom(const float bottom);
            void setTop(const float top);

            float width() const;
            float height() const;
            void setWidth(const float width);
            void setHeight(const float height);

            sf::Vector2f center() const;
            void setCenter(const sf::Vector2f& center);

            float centerX() const;
            float centerY() const;
            void setCenterX(const float x);
            void setCenterY(const float y);

            sf::Vector2f move(const float& dt);
            void move(const sf::Vector2f& delta);
            bool collide(const og::Transform& t) const;
            bool collide(const sf::Vector2f& pos, const sf::Vector2f& size) const;
            og::Transform shrink() const;

    };
    
} // namespace re


#endif