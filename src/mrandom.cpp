#include "mrandom.hpp"
#include "constants.hpp"


void ze::mrandom_init() {
    ze::gRandom.randXPos = std::uniform_real_distribution<float>(0.0f, ZE_SCREEN_W);
    ze::gRandom.randYPos = std::uniform_real_distribution<float>(-ZE_SCREEN_H, 0.0f);
    ze::gRandom.randSpeed = std::uniform_real_distribution<float>(30.0f, 300.0f);
}


float ze::mrandon_randXPos() {
    return ze::gRandom.randXPos(ze::gRandom.generator);
}


float ze::mrandon_randYPos() {
    return ze::gRandom.randYPos(ze::gRandom.generator);
}


float ze::mrandom_randSpeed() {
    return ze::gRandom.randSpeed(ze::gRandom.generator);
}