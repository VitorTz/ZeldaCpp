#ifndef ZELDACPP_RECT_H
#define ZELDACPP_RECT_H
#include <SFML/System/Vector2.hpp>


namespace ze {

    class Rect {

    private:
        sf::Vector2f pos;
        sf::Vector2f size;

    public:
        Rect() = default;
        Rect(
            sf::Vector2f pos,
            sf::Vector2f size
        ) : pos(pos), size(size) { }

        void moveHorizontal(float x);
        void moveVertical(float y);
        void move(sf::Vector2f distance);

        [[nodiscard]] sf::Vector2f getPos() const;
        [[nodiscard]] sf::Vector2f getSize() const;

        void setPos(sf::Vector2f pos);
        void setSize(sf::Vector2f size);

        [[nodiscard]] float left() const;
        [[nodiscard]] float right() const;
        [[nodiscard]] float top() const;
        [[nodiscard]] float bottom() const;

        void setLeft(float left);
        void setRight(float right);
        void setTop(float top);
        void setBottom(float bottom);

        [[nodiscard]] sf::Vector2f center() const;
        void setCenter(sf::Vector2f center);

        [[nodiscard]] float centerX() const;
        [[nodiscard]] float centerY() const;
        void setCenterX(float x);
        void setCenterY(float y);

        [[nodiscard]] float width() const;
        [[nodiscard]] float height() const;
        void setWidth(float width);
        void setHeight(float height);

        [[nodiscard]] Rect shrink(sf::Vector2f scale) const;

        static bool collide(const ze::Rect& r1, const ze::Rect& r2);

    };


}

#endif //ZELDACPP_RECT_H
