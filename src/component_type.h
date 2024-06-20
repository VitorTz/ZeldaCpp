#pragma once
#include <unordered_map>
#include <typeinfo>
#include <cassert>
#include "types.h"
#include "components.h"


namespace ze {


	class ComponentType {

	private:
		ze::component id = 0;

	private:
		std::unordered_map<const char*, ze::component> typeToComponentId{};

	public:
		ComponentType() {
			this->typeToComponentId.reserve(ZE_NUM_COMPONENTS / static_cast<std::size_t>(this->typeToComponentId.max_load_factor()));
			this->typeToComponentId.insert({ typeid(ze::transform_t).name(), id++});
			this->typeToComponentId.insert({ typeid(ze::sprite_t).name(), id++ });
			this->typeToComponentId.insert({ typeid(ze::controller_t).name(), id++ });
			this->typeToComponentId.insert({ typeid(ze::obstacle_t).name(), id++ });
			this->typeToComponentId.insert({ typeid(ze::player_t).name(), id++ });
			this->typeToComponentId.insert({ typeid(ze::sprite_animation_t).name(), id++ });
			assert(this->typeToComponentId.size() == ZE_NUM_COMPONENTS);
		}
		template<typename T>
		ze::component get() {
			return this->typeToComponentId[typeid(T).name()];
		}

	};

	inline ze::ComponentType gComponentType{};

}