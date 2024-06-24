#include "weapon.hpp"
#include "texture_pool.hpp"


void ze::weapon_load_textures() {
    ze::gWeaponTextureMap[0].insert({'u', ze::gTexturePool.load("assets/graphics/weapons/axe/u.png")});
    ze::gWeaponTextureMap[0].insert({'d', ze::gTexturePool.load("assets/graphics/weapons/axe/d.png")});
    ze::gWeaponTextureMap[0].insert({'l', ze::gTexturePool.load("assets/graphics/weapons/axe/l.png")});
    ze::gWeaponTextureMap[0].insert({'r', ze::gTexturePool.load("assets/graphics/weapons/axe/r.png")});
    
    ze::gWeaponTextureMap[1].insert({'u', ze::gTexturePool.load("assets/graphics/weapons/lance/u.png")});
    ze::gWeaponTextureMap[1].insert({'d', ze::gTexturePool.load("assets/graphics/weapons/lance/d.png")});
    ze::gWeaponTextureMap[1].insert({'l', ze::gTexturePool.load("assets/graphics/weapons/lance/l.png")});
    ze::gWeaponTextureMap[1].insert({'r', ze::gTexturePool.load("assets/graphics/weapons/lance/r.png")});

    ze::gWeaponTextureMap[2].insert({'u', ze::gTexturePool.load("assets/graphics/weapons/sai/u.png")});
    ze::gWeaponTextureMap[2].insert({'d', ze::gTexturePool.load("assets/graphics/weapons/sai/d.png")});
    ze::gWeaponTextureMap[2].insert({'l', ze::gTexturePool.load("assets/graphics/weapons/sai/l.png")});
    ze::gWeaponTextureMap[2].insert({'r', ze::gTexturePool.load("assets/graphics/weapons/sai/r.png")});

    ze::gWeaponTextureMap[3].insert({'u', ze::gTexturePool.load("assets/graphics/weapons/sword/u.png")});
    ze::gWeaponTextureMap[3].insert({'d', ze::gTexturePool.load("assets/graphics/weapons/sword/d.png")});
    ze::gWeaponTextureMap[3].insert({'l', ze::gTexturePool.load("assets/graphics/weapons/sword/l.png")});
    ze::gWeaponTextureMap[3].insert({'r', ze::gTexturePool.load("assets/graphics/weapons/sword/r.png")});
}


Rectangle ze::weapon_get_rect(
    const Vector2 pos,
    const char direction,
    const ze::Weapon weapon
) {
    Rectangle rect;
    Vector2 v;
    v = ze::gWeaponSize[weapon].at(direction);    
    rect.width = v.x;
    rect.height = v.y;
    v = ze::gWeaponOffset.at(direction);
    rect.x = pos.x + v.x;
    rect.y = pos.y + v.y;
    return rect;
}