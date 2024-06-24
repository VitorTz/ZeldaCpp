#ifndef ZELDA_WEAPON_HPP
#define ZELDA_WEAPON_HPP
#include <unordered_map>
#include <raylib.h>
#include "texture_pool.hpp"


namespace ze {

    inline std::unordered_map<char, Texture2D> gWeaponTextureMap[4];

    const static std::unordered_map<char, Vector2> gWeaponSize[4] = {
        { // axe
            {'u', Vector2{30.0f, 35.0f}},
            {'d', Vector2{30.0f, 35.0f}},
            {'l', Vector2{35.0f, 30.0f}},
            {'r', Vector2{35.0f, 30.0f}}
        },
        { // lance
            {'u', Vector2{15.0f, 40.0f}},
            {'d', Vector2{15.0f, 40.0f}},
            {'l', Vector2{40.0f, 15.0f}},
            {'r', Vector2{40.0f, 15.0f}}
        },
        { // sai
            {'u', Vector2{25.0f, 30.0f}},
            {'d', Vector2{25.0f, 30.0f}},
            {'l', Vector2{30.0f, 25.0f}},
            {'r', Vector2{30.0f, 25.0f}}
        },
        { // sword
            {'u', Vector2{15.0f, 35.0f}},
            {'d', Vector2{15.0f, 35.0f}},
            {'l', Vector2{35.0f, 15.0f}},
            {'r', Vector2{35.0f, 15.0f}}
        }
    };

    const static std::unordered_map<char, Vector2> gWeaponOffset = {
        {'d', Vector2{0.0f, 30.0f}},
        {'u', Vector2{-25.0f, -75.0f}},
        {'l', Vector2{-75.0f, 5.0f}},
        {'r', Vector2{30.0f, 5.0f}}        
    };

    enum Weapon {
        Axe,
        Lance,
        Sai,
        Sword
    };

    void weapon_load_textures();    

    Rectangle weapon_get_rect(const Vector2 pos, const char directon, const ze::Weapon weapon);
    
} // namespace ze



#endif