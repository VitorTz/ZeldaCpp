#ifndef ZELDA_WEAPONS_HPP
#define ZELDA_WEAPONS_HPP
#include <raylib.h>
#include <unordered_map>
#include <string>
#include "types.hpp"


namespace ze {


    static const Vector2 WEAPON_SIZE[5] = {
        {30, 20},
        {60, 15},        
        {20, 30},
        {25, 15}
    };


    static const std::unordered_map<char, Vector2> WEAPON_HITBOX_OFFSET = {
        {'d', {0.0f, 10.0f}},
        {'u', {0.0f, -15.0f}},
        {'l', {-15.0f, 10.0f}},
        {'r', {10.0f, 10.0f}}
    };


    static const std::unordered_map<char, Vector2> WEAPON_OFFSET = {
        {'d', {0.0f, 30.0f}},
        {'u', {-25.0f, -75.0f}},
        {'l', {-75.0f, 5.0f}},
        {'r', {30.0f, 5.0f}}
    };


    Vector2 get_weapon_size(const char direction, ze::Weapon weapon);

    
} // namespace ze



#endif