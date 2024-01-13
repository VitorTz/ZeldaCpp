#ifndef MANGA_READER_TRANSFORM_HPP
#define MANGA_READER_TRANSFORM_HPP
#include <SFML/System/Vector2.hpp>



namespace ze {

    class Transform {

        public:
            sf::Vector2f pos;
            sf::Vector2f size;
            sf::Vector2f scale;

        public:
            Transform();
            Transform(const sf::Vector2f& pos);
            Transform(
                const sf::Vector2f& pos,
                const sf::Vector2f& size,
                const sf::Vector2f& scale
            );
            Transform(
                const sf::Vector2f& pos,
                const sf::Vector2f& size
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

            void moveY(const float y);
            void moveX(const float x);
            void move(const sf::Vector2f& v);

            bool collide(const ze::Transform& t);

    };
    
} // namespace re


#endif