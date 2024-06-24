#ifndef ZELDA_MRANDOM_HPP
#define ZELDA_MRANDOM_HPP
#include <random>



namespace ze {

    typedef struct mrandom {
        std::default_random_engine generator{};
        std::uniform_real_distribution<float> randXPos;
        std::uniform_real_distribution<float> randYPos;
        std::uniform_real_distribution<float> randSpeed;
    } mrandom_t;    

    void mrandom_init();

    float mrandon_randXPos();

    float mrandon_randYPos();

    float mrandom_randSpeed();

    inline ze::mrandom_t gRandom{};
    
} // namespace ze



#endif