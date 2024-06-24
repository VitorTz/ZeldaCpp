#ifndef ZELDA_COMPONENT_TYPE_HPP
#define ZELDA_COMPONENT_TYPE_HPP
#include <unordered_map>
#include <typeinfo>
#include <cassert>
#include "component.hpp"
#include "types.hpp"
#include "player.hpp"


namespace ze {


    static const std::unordered_map<const char*, ze::component_t> gTypeMap = {
        {typeid(ze::transform_t).name(), 0},
        {typeid(ze::sprite_t).name(), 1},
        {typeid(ze::sprite_animation_t).name(), 2},
        {typeid(ze::player_t).name(), 3},
        {typeid(ze::obstacle_t).name(), 4}
    };
    
    template<typename T>
    ze::component_t getType() {
        return gTypeMap.at(typeid(T).name());
    }
    
} // namespace ze



#endif
