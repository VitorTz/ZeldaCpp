#pragma once
#include <unordered_map>
#include <typeinfo>
#include "types.h"
#include "components.h"


namespace ze {


	const static std::unordered_map<const char*, ze::component> typeToComponent = {
		{ typeid(ze::transform_t).name(), 0},
		{ typeid(ze::sprite_t).name(), 1},
		{ typeid(ze::controller_t).name(), 2},
		{ typeid(ze::obstacle_t).name(), 3},
		{ typeid(ze::player_t).name(), 4},
		{ typeid(ze::sprite_animation_t).name(), 5}
	};

	template<typename T>
	ze::component getComponentType() {
		const char* type_name = typeid(T).name();
		return ze::typeToComponent.at(type_name);
	}
	
}