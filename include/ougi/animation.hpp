#pragma once
#include <vector>
#include <map>
#include <cmath>
#include <filesystem>
#include <algorithm>
#include "sprite.hpp"


namespace ze {


    namespace ougi {


        enum AnimationId {
            
            PlayerLeft,
            PlayerLeftIdle,
            PlayerLeftAttack,
            PlayerRight,
            PlayerRightIdle,
            PlayerRightAttack,
            PlayerUp,
            PlayerUpIdle,
            PlayerUpAttack,
            PlayerDown,
            PlayerDownIdle,
            PlayerDownAttack
            
        };

        const std::vector<ze::ougi::AnimationId> PLAYER_ANIMATIONS = {
            ze::ougi::AnimationId::PlayerLeftIdle,
            ze::ougi::AnimationId::PlayerRightIdle,
            ze::ougi::AnimationId::PlayerUpIdle,
            ze::ougi::AnimationId::PlayerDownIdle,
            ze::ougi::AnimationId::PlayerDown,
            ze::ougi::AnimationId::PlayerLeft,
            ze::ougi::AnimationId::PlayerRight,
            ze::ougi::AnimationId::PlayerUp,
            ze::ougi::AnimationId::PlayerLeftAttack,
            ze::ougi::AnimationId::PlayerRightAttack,
            ze::ougi::AnimationId::PlayerUpAttack,
            ze::ougi::AnimationId::PlayerDownAttack
        };

        const std::map<ze::ougi::AnimationId, std::string> spriteDirByAnimation = {
            {ze::ougi::AnimationId::PlayerLeftIdle, "res/graphics/player/left_idle"},
            {ze::ougi::AnimationId::PlayerRightIdle, "res/graphics/player/right_idle"},
            {ze::ougi::AnimationId::PlayerUpIdle, "res/graphics/player/up_idle"},
            {ze::ougi::AnimationId::PlayerDownIdle, "res/graphics/player/down_idle"},
            {ze::ougi::AnimationId::PlayerLeft, "res/graphics/player/left"},
            {ze::ougi::AnimationId::PlayerRight, "res/graphics/player/right"},
            {ze::ougi::AnimationId::PlayerUp, "res/graphics/player/up"},
            {ze::ougi::AnimationId::PlayerDown, "res/graphics/player/down"},
            {ze::ougi::AnimationId::PlayerLeftAttack, "res/graphics/player/left_attack"},
            {ze::ougi::AnimationId::PlayerRightAttack, "res/graphics/player/right_attack"},
            {ze::ougi::AnimationId::PlayerUpAttack, "res/graphics/player/up_attack"},
            {ze::ougi::AnimationId::PlayerDownAttack, "res/graphics/player/down_attack"}
        };

        const int ANIMATION_SPEED = 5;

        class Animation {

            public:
                const ze::ougi::AnimationId animationId;

            private:
                std::vector<ze::ougi::Sprite*> sprites;
                float currentSpriteIndex;                

            public:
                Animation(const ze::ougi::AnimationId& animationId);
                ~Animation();
                void update(const float& dt);
                void draw(sf::RenderWindow& window, const ze::Rect& rect);
                void reset();

        };


        class AnimationGroup {

            private:
                std::map<ze::ougi::AnimationId, ze::ougi::Animation*> animations;
                ze::ougi::AnimationId animationId;
        
            public:                
                AnimationGroup(const std::vector<ze::ougi::AnimationId>& animations);
                ~AnimationGroup();
                void add(const ze::ougi::AnimationId& animation);
                void change(const ze::ougi::AnimationId& animationId);
                void update(const float& dt);
                void draw(sf::RenderWindow& window, const ze::Rect& rect);
                const ze::ougi::AnimationId& getAnimationId() const;

        };

        
    } // namespace ougi
    
    
} // namespace ze
