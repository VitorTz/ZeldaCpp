#pragma once
#include <array>
#include <memory>
#include <cassert>
#include "component_array.h"
#include "components.h"
#include "component_type.h"


namespace ze {


	class ComponentManager {

	private:		
		std::unordered_map<ze::ComponentId, std::unique_ptr<ze::IComponentArray>> componentArrayMap{};
		ze::ComponentArray<ze::transform_t>* transformArray;
		std::size_t mSize = 0;

	public:
		ComponentManager() {
			this->componentArrayMap.reserve(ZE_NUM_COMPONENTS / this->componentArrayMap.max_load_factor());
			
			// transform
			this->componentArrayMap.emplace(
				ze::gComponentType.get<ze::transform_t>(),
				std::make_unique<ze::ComponentArray<ze::transform_t>>()
			);
			this->transformArray = static_cast<ze::ComponentArray<ze::transform_t>*>(this->componentArrayMap[ze::gComponentType.get<ze::transform_t>()].get());
			
			// sprite
			this->componentArrayMap.emplace(
				ze::gComponentType.get<ze::sprite_t>(),
				std::make_unique<ze::ComponentArray<ze::sprite_t>>()
			);

			// controller
			this->componentArrayMap.emplace(
				ze::gComponentType.get<ze::controller_t>(),
				std::make_unique<ze::ComponentArray<ze::controller_t>>()
			);

			assert(this->componentArrayMap.size() == ZE_NUM_COMPONENTS);
		}
		template<typename T>
		void addComponent(const ze::Entity e, T c) {
			const ze::ComponentId id = ze::gComponentType.get<T>();
			ze::ComponentArray<T>* arr = static_cast<ze::ComponentArray<T>*>(this->componentArrayMap[id].get());
			arr->insert(e, std::move(c));
			this->mSize++;
		}
		template<typename T>
		void rmvComponent(const ze::Entity e) {
			this->componentArrayMap[ze::gComponentType.get<T>()]->erase(e);
			this->mSize--;
		}
		template<typename T>
		T& getComponent(const ze::Entity e) {
			const ze::ComponentId id = ze::gComponentType.get<T>();
			ze::ComponentArray<T>* arr = static_cast<ze::ComponentArray<T>*>(this->componentArrayMap[id].get());
			return arr->at(e);			
		}

		ze::transform& get_transform(const ze::Entity e) {
			return this->transformArray->at(e);
		}

		void entityDestroy(ze::Entity e) {
			for (auto& pair : this->componentArrayMap) {
				this->mSize -= pair.second->erase(e) ? 1 : 0;
			}
		}
		void clear() {
			for (auto& pair : this->componentArrayMap) {
				pair.second->clear();
			}
			this->mSize = 0;
		}

		std::size_t size() const {
			return this->mSize;
		}

	};

}