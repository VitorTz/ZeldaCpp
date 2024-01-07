#pragma once
#include <SFML/Window/Keyboard.hpp>
#include "../util/direction.hpp"
#include "animation.hpp"
#include "sprite.hpp"
#include "mask.hpp"


namespace ze {

    namespace ougi {


        class Player : public Sprite {

            private:                
                sf::Vector2f direction;
                ze::ougi::AnimationGroup animation;
                ze::Direction horizontalDirection;
                ze::Direction verticalDirection;
            
            private:
                void move(const float& dt);
                void handleAnimationChange();

            public:
                Player();
                ~Player() override;
                void update(const float& dt) override;
                void draw(sf::RenderWindow& window) override;
                void setAnimation(const ze::ougi::AnimationId& animationId);

        };
        
    } // namespace ougi
    
    
} // namespace ze
