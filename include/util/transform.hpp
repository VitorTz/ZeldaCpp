#ifndef MANGA_READER_TRANSFORM_HPP
#define MANGA_READER_TRANSFORM_HPP
#include <SFML/System/Vector2.hpp>
#include "z_index.hpp"


namespace ze {

    void normalizeVector(sf::Vector2f& v);

    class Transform {

        public:
            sf::Vector2f pos;
            sf::Vector2f size;
            sf::Vector2f scale;
            sf::Vector2f direction;
            const ze::Zindex zIndex;
            float speed;

        public:
            Transform(
                const sf::Vector2f& pos,
                const ze::Zindex zIndex
            );
            explicit Transform(const ze::Zindex zIndex);
            Transform(
                const sf::Vector2f& pos,
                const sf::Vector2f& size,
                const sf::Vector2f& scale,
                const ze::Zindex zIndex
            );
            Transform(
                const sf::Vector2f& pos,
                const sf::Vector2f& size,
                const ze::Zindex zIndex
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

            void move(const float& dt);
            void move(const sf::Vector2f& delta);
            bool collide(const ze::Transform& t);

    };
    
} // namespace re


#endif