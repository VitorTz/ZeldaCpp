#include "weapons.hpp"
#include "util.hpp"


Vector2 ze::get_weapon_size(const char direction, const ze::Weapon weapon) {
    Vector2 size = WEAPON_SIZE[weapon];
    if (direction == 'u' || direction == 'd') {
        ze::swap_vec(&size);
    }
    return size;
}