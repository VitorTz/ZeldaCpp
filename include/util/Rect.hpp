#ifndef FCAEA731_FD7D_4FC4_8807_B730E22CB386
#define FCAEA731_FD7D_4FC4_8807_B730E22CB386
#include <SFML/System/Vector2.hpp>


namespace ze {


    class Rect {


        public:
            sf::Vector2f pos;
            sf::Vector2f size;            
        
        public:
            Rect() = default;
            Rect(const sf::Vector2f pos_, const sf::Vector2f size_) : pos(pos_), size(size_) { }
        
        public:
            
            float left() const;
            float right() const;
            float bottom() const;
            float top() const;

            void setLeft(float left);
            void setRight(float right);
            void setBottom(float bottom);
            void setTop(float top);

            sf::Vector2f center() const;
            void setCenter(sf::Vector2f center);

            float centerX() const;
            float centerY() const;

            void setCenterX(float x);
            void setCenterY(float y);

            float width() const;
            float height() const;

            static bool collide(const ze::Rect& r1, const ze::Rect& r2);

    };
    
} // namespace ze


#endif /* FCAEA731_FD7D_4FC4_8807_B730E22CB386 */
