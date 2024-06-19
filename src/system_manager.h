#pragma once
#include <unordered_map>
#include <array>
#include <vector>
#include <cassert>
#include "constants.h"
#include "components.h"
#include "system.h"
#include "component_type.h"


namespace ze {

	class SystemManager {	

	private:
		std::unordered_map<ze::ComponentId, std::unique_ptr<ze::System>> systemMap{};
		std::unordered_map<ze::Entity, std::unordered_set<ze::ComponentId>> entityToSystems{};

	public:		
		SystemManager() {
			this->entityToSystems.reserve(ZE_MAX_ENTITIES / this->entityToSystems.max_load_factor());
			for (ze::Entity i = 0; i < ZE_MAX_ENTITIES; i++) {
				this->entityToSystems.insert({ i, {} });
			}

			this->systemMap.reserve(ZE_NUM_COMPONENTS / this->systemMap.max_load_factor());
			
			// transform
			this->systemMap.emplace(
				gComponentType.get<ze::transform_t>(),
				std::make_unique<ze::TransformSystem>()
			);

			// sprite
			this->systemMap.emplace(
				gComponentType.get<ze::sprite_t>(),
				std::make_unique<ze::SpriteSystem>()
			);

			// controller
			this->systemMap.emplace(
				gComponentType.get<ze::controller_t>(),
				std::make_unique<ze::ControllerSystem>()
			);

			assert(this->systemMap.size() == ZE_NUM_COMPONENTS);
		}
		template<typename T>
		void addToSystem(const ze::Entity e) {
			const ze::ComponentId id = gComponentType.get<T>();
			this->systemMap[id]->entities.insert(e);
			this->entityToSystems[e].insert(id);
		}
		template<typename T>
		void rmvFromSystem(const ze::Entity e) {
			const ze::ComponentId id = gComponentType.get<T>();
			this->systemMap[id]->entities.erase(e);
			this->entityToSystems[e].erase(id)
		}

		template<typename T>
		bool isOnSystem(const ze::Entity e) const {
			const ze::ComponentId id = ze::gComponentType.get<T>();
			const std::unordered_set<ze::ComponentId>* s = this->entityToSystems[e];
			return s->find(e) != s->end();
		}

		template<typename T>
		const std::unordered_set<ze::Entity>* getEntitiesBySystem() {
			const ze::ComponentId id = ze::gComponentType.get<T>();
			return &this->systemMap[id]->entities;
		}

		void entityDestroy(ze::Entity e) {
			for (const ze::ComponentId id : this->entityToSystems[e]) {
				this->systemMap[id]->entities.erase(e);
			}
			this->entityToSystems[e].clear();
		}
		void clear() {
			for (auto& pair : this->systemMap) {
				pair.second->entities.clear();
			}
			for (auto& pair : this->entityToSystems) {
				pair.second.clear();
			}
		}
		void update(float dt) {
			for (auto& pair : this->systemMap) {
				pair.second->update(dt);
			}
		}
		void draw(const ze::Entity e) {
			for (const ze::ComponentId id : this->entityToSystems[e]) {
				this->systemMap[id]->draw(e);
			}
		}

	};

}