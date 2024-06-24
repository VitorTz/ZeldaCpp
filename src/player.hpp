#ifndef ZELDA_PLAYER_HPP
#define ZELDA_PLAYER_HPP
#include <raylib.h>
#include "weapon.hpp"
#include "types.hpp"


namespace ze {

    typedef struct player {
        ze::entity_t playerEntity{};
        ze::entity_t playerWeaponEntity{};
        char action = 'm';
        char direction[2] = {'i', 'd'};
        float attack_timer = 0.0f;
        Vector2 lastPos = {2000.0f, 1430.0f};
        Rectangle collideBox = {0.0f, 0.f, 50.0f, 50.0f};
        ze::Weapon weapon = ze::Sword;
    } player_t;    

    inline ze::player_t gPlayer{};
    
} // namespace ze



#endif