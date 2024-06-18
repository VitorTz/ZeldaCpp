#ifndef ZELDA_SPRITE_H
#define ZELDA_SPRITE_H


namespace ze {


    class Sprite {

        public:
            virtual ~Sprite() = default;
            virtual void update(float dt) = 0;
            virtual void draw() = 0;

    };
    
} // namespace ze


#endif