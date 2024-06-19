#pragma once
#include <unordered_map>
#include <typeinfo>
#include <cassert>
#include "types.h"
#include "components.h"


namespace ze {


	class ComponentType {

	private:
		ze::ComponentId id = 0;

	private:
		std::unordered_map<const char*, ze::ComponentId> typeToComponentId{};

	public:
		ComponentType() {
			this->typeToComponentId.reserve(ZE_NUM_COMPONENTS / this->typeToComponentId.max_load_factor());
			this->typeToComponentId.insert({ typeid(ze::transform_t).name(), id++});
			this->typeToComponentId.insert({ typeid(ze::sprite_t).name(), id++ });
			this->typeToComponentId.insert({ typeid(ze::controller_t).name(), id++ });
			assert(this->typeToComponentId.size() == ZE_NUM_COMPONENTS);
		}
		template<typename T>
		ze::ComponentId get() {
			return this->typeToComponentId[typeid(T).name()];
		}

	};

	inline ze::ComponentType gComponentType{};

}