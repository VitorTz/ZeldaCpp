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
		std::unordered_map<ze::component, std::unique_ptr<ze::IComponentArray>> componentArrayMap{};
		ze::ComponentArray<ze::transform_t>* transformArray;
		std::size_t mSize = 0;

	public:
		ComponentManager() {
			this->componentArrayMap.reserve(ZE_NUM_COMPONENTS);
			
			// transform
			this->componentArrayMap.emplace(
				ze::getComponentType<ze::transform_t>(),
				std::make_unique<ze::ComponentArray<ze::transform_t>>()
			);
			
			this->transformArray = static_cast<ze::ComponentArray<ze::transform_t>*>(
				this->componentArrayMap.at(ze::getComponentType<ze::transform_t>()).get()
			);
			
			// sprite
			this->componentArrayMap.emplace(
				ze::getComponentType<ze::sprite_t>(),
				std::make_unique<ze::ComponentArray<ze::sprite_t>>()
			);

			// controller
			this->componentArrayMap.emplace(
				ze::getComponentType<ze::controller_t>(),
				std::make_unique<ze::ComponentArray<ze::controller_t>>()
			);

			// obstacle
			this->componentArrayMap.emplace(
				ze::getComponentType<ze::obstacle_t>(),
				std::make_unique<ze::ComponentArray<ze::obstacle_t>>()
			);

			// player
			this->componentArrayMap.emplace(
				ze::getComponentType<ze::player_t>(),
				std::make_unique<ze::ComponentArray<ze::player_t>>()
			);

			// sprite animation
			this->componentArrayMap.emplace(
				ze::getComponentType<ze::sprite_animation_t>(),
				std::make_unique<ze::ComponentArray<ze::sprite_animation_t>>()
			);

			assert(this->componentArrayMap.size() == ZE_NUM_COMPONENTS);
		}

		template<typename T>
		void addComponent(const ze::entity e, T c) {
			const ze::component id = ze::getComponentType<T>();
			ze::ComponentArray<T>* arr = static_cast<ze::ComponentArray<T>*>(this->componentArrayMap[id].get());
			arr->insert(e, std::move(c));
			this->mSize++;
		}

		template<typename T>
		void rmvComponent(const ze::entity e) {
			this->componentArrayMap[ze::getComponentType<T>()]->erase(e);
			this->mSize--;
		}

		template<typename T>
		T& getComponent(const ze::entity e) {
			const ze::component id = ze::getComponentType<T>();
			ze::ComponentArray<T>* arr = static_cast<ze::ComponentArray<T>*>(this->componentArrayMap[id].get());
			return arr->at(e);			
		}

		ze::transform& get_transform(const ze::entity e) {
			return this->transformArray->at(e);
		}

		void entityDestroy(const ze::entity e) {
			for (auto& pair : this->componentArrayMap) {
				const bool erased = pair.second->erase(e);
				this->mSize -= erased ? 1 : 0;
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