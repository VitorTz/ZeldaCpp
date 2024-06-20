#pragma once
#include "entity_manager.h"
#include "component_manager.h"
#include "system_manager.h"
#include <map>
#include <vector>
#include <raymath.h>
#include <algorithm>
#include <iostream>
#include "util.h"


namespace ze {


	class ECS {

	private:		
		std::map<ze::z_index, std::vector<ze::entity>> camera{};
		std::array<bool, ZE_MAX_ENTITIES> isOnCamera{};
		std::queue<ze::entity> entitiesToDestroy{};
		bool should_clear_all_entities = false;

	private:
		ze::EntityManager entity{};
		ze::SystemManager system{};	
		ze::ComponentManager component{};

	public:
		ECS() {			
			for (ze::z_index i = ZE_MIN_ZINDEX; i <= ZE_MAX_ZINDEX; i++) {
				this->camera.insert({ i, {} });
				this->camera[i].reserve(sizeof(ze::entity) * ZE_MAX_ENTITIES);
			}			
		}

		ze::entity entityCreate(const ze::z_index zIndex, const bool _isOnCamera) {
			assert(zIndex >= ZE_MIN_ZINDEX && zIndex <= ZE_MAX_ZINDEX);
			const ze::entity e = this->entity.entityCreate();
			this->addComponent<ze::transform_t>(e, ze::transform_t{ zIndex });
			if (_isOnCamera == true) {
				this->submitToCamera(e, zIndex);
			}			
			return e;
		}

		void submitEntityToDestroyQueue(const ze::entity e) {
			this->entitiesToDestroy.push(e);
		}		
		
		template<typename T>
		void addComponent(const ze::entity e, T c) {
			this->component.addComponent<T>(e, std::move(c));
			this->system.addToSystem<T>(e);
		}
		
		template<typename T>
		void rmvComponent(const ze::entity e) {
			this->component.rmvComponent<T>(e);
			this->system.rmvFromSystem<T>(e);
		}

		template<typename T>
		T& getComponent(const ze::entity e) {
			return this->component.getComponent<T>(e);
		}

		ze::transform_t& get_transform(const ze::entity e) {
			return this->component.get_transform(e);			
		}

		void submitToCamera(const ze::entity e, const ze::z_index zIndex) {
			if (this->isOnCamera[e] == false) {
				this->isOnCamera[e] = true;
				this->camera[zIndex].push_back(e);
			}
		}

		void rmvFromCamera(ze::entity e) {
			if (this->isOnCamera[e] == true) {
				this->isOnCamera[e] = false;				
				std::vector<ze::entity>& v = this->camera[this->get_transform(e).zIndex];
				for (std::size_t i = 0; i < v.size(); i++) {
					if (v[i] == e) {
						v.erase(v.begin() + i);
						break;
					}
				}
			}
		}

		template<typename T>
		bool isEntityOnSystem(const ze::entity e) const {
			return this->system.isEntityOnSystem<T>(e);
		}

		template<typename T>
		const std::unordered_set<ze::entity>* getEntitiesBySystem() {
			return this->system.getEntitiesBySystem<T>();
		}

		bool obstacleCollide(const ze::entity e) {			
			const Rectangle eRect = this->get_transform(e).rect;
			for (const ze::entity otherEntity : *this->system.getEntitiesBySystem<ze::obstacle_t>()) {
				if (
					e != otherEntity && CheckCollisionRecs(eRect, this->get_transform(otherEntity).rect)
					) {
					return true;
				}
			}
		}

		void update(const float dt) {
			this->system.update(dt);

			if (this->should_clear_all_entities == true) {
				this->should_clear_all_entities = false;
				
				for (auto& pair : this->camera) {
					pair.second.clear();
				}

				for (int i = 0; i < this->isOnCamera.size(); i++) {
					this->isOnCamera[i] = false;
				}

				this->entitiesToDestroy = std::queue<ze::entity>();

				this->entity.clear();
				this->component.clear();
				this->system.clear();

			}

			while (this->entitiesToDestroy.empty() == false) {
				const ze::entity e = this->entitiesToDestroy.front();
				this->entitiesToDestroy.pop();				
				this->rmvFromCamera(e);
				this->entity.entityDestroy(e);
				this->component.entityDestroy(e);
				this->system.entityDestroy(e);
			}
		}

		void draw() {
			// zIndex and ySort camera
			for (auto& pair : this->camera) {
				std::sort(
					pair.second.begin(),
					pair.second.end(),
					[this](const ze::entity l, const ze::entity r) {
						const ze::transform_t& lt = this->get_transform(l);
						const ze::transform_t& rt = this->get_transform(r);
						return (
						 	lt.rect.x + lt.rect.height / 2.0f < rt.rect.y + rt.rect.height / 2.0f
						);						
					}
				);				
				for (const ze::entity e : pair.second) {
					this->system.draw(e);
				}
			}
		}

		void clear() {
			this->should_clear_all_entities = true;
		}

		std::size_t entitiesAlive() const {
			return this->entity.size();
		}

		std::size_t componentsAlive() const {
			return this->component.size();
		}

		std::size_t cameraSize() const {
			std::size_t s = 0;
			for (const auto& pair : this->camera) {
				s += pair.second.size();
			}
			return s;
		}

	};


	inline ze::ECS gEcs{};

}