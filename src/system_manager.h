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
		std::unordered_map<ze::component, std::unique_ptr<ze::System>> systemMap{};
		std::unordered_map<ze::entity, std::unordered_set<ze::component>> entityToSystems{};

	public:		
		SystemManager() {
			this->entityToSystems.reserve(ZE_MAX_ENTITIES / this->entityToSystems.max_load_factor());
			for (ze::entity i = 0; i < ZE_MAX_ENTITIES; i++) {
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

			// obstacle
			this->systemMap.emplace(
				gComponentType.get<ze::obstacle_t>(),
				std::make_unique<ze::ObstacleSystem>()
			);

			// player
			this->systemMap.emplace(
				gComponentType.get<ze::player_t>(),
				std::make_unique<ze::PlayerSystem>()
			);

			assert(this->systemMap.size() == ZE_NUM_COMPONENTS);
		}
		template<typename T>
		void addToSystem(const ze::entity e) {
			const ze::component id = gComponentType.get<T>();
			this->systemMap[id]->entities.insert(e);
			this->entityToSystems[e].insert(id);
		}
		template<typename T>
		void rmvFromSystem(const ze::entity e) {
			const ze::component id = gComponentType.get<T>();
			this->systemMap[id]->entities.erase(e);
			this->entityToSystems[e].erase(id);
		}

		template<typename T>
		bool isEntityOnSystem(const ze::entity e) const {
			const ze::component id = ze::gComponentType.get<T>();
			const std::unordered_set<ze::entity>* s = &this->systemMap.at(id)->entities;
			return s->find(e) != s->end();
		}

		template<typename T>
		const std::unordered_set<ze::entity>* getEntitiesBySystem() {
			const ze::component id = ze::gComponentType.get<T>();
			return &this->systemMap[id]->entities;
		}

		void entityDestroy(ze::entity e) {		
			for (const ze::component id : this->entityToSystems[e]) {
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
		void draw(const ze::entity e) {
			for (const ze::component id : this->entityToSystems[e]) {
				this->systemMap[id]->draw(e);
			}
		}

	};

}