#ifndef ZELDA_ECS_HPP
#define ZELDA_ECS_HPP
#include <algorithm>
#include <vector>
#include <map>
#include "entity_manager.hpp"
#include "component_manager.hpp"
#include "system_manager.hpp"
#include "util.hpp"
#include "globals.hpp"


namespace ze {


    class ECS {

        private:
            ze::EntityManager entity;
            ze::ComponentManager component;
            ze::SystemManager system;
            std::queue<ze::entity_t> entitiesToDestroy{};
            std::map<ze::zindex_t, std::vector<std::pair<float, ze::entity_t>>> camera{};
            std::array<bool, ZE_MAX_ENTITIES> isOnCamera{};
            bool shouldClearAllEntities = false;
        
        public:
            ECS() {
                for (ze::zindex_t i = ZE_MAX_ZINDEX; i <= ZE_MAX_ZINDEX; i++) {
                    this->camera.insert({i, {}});
                    this->camera[i].reserve(ZE_MAX_ENTITIES * sizeof(ze::entity_t));
                }
            }
            
            ze::entity_t entityCreate(const ze::zindex_t z_index, const bool onCamera) {
                const ze::entity_t e = this->entity.entityCreate();                
                this->addComponent<ze::transform_t>(e, ze::transform_t{}, ze::TransformId);
                if (onCamera) this->submitToCamera(e);
                return e;
            }

            void entityDestroy(const ze::entity_t e) {
                this->entitiesToDestroy.push(e);
            }

            void submitToCamera(const ze::entity_t e) {
                if (this->isOnCamera[e] == false) {
                    this->isOnCamera[e] = true;
                    const ze::zindex_t z_index = this->component.getTransform(e).z_index;
                    this->camera[z_index].push_back({0.0f, e});
                }
            }

            void rmvFromCamera(const ze::entity_t e) {
                if (this->isOnCamera[e] == true) {
                    this->isOnCamera[e] = false;
                    const ze::zindex_t z_index = this->component.getTransform(e).z_index;
                    std::vector<std::pair<float, ze::entity_t>>& v = this->camera[z_index];
                    for (std::size_t i = 0; i < v.size(); i++) {
                        if (v[i].second == e) {
                            v.erase(v.begin() + i);
                            return;
                        }
                    }
                }
            }

            bool isEntityOnCamera(const ze::entity_t e) {
                return this->isOnCamera[e];
            }

            template<typename T>
            void addComponent(const ze::entity_t e, T c, const ze::ComponentId id) {
                this->component.insert(e, std::move(c), id);
                this->system.addToSystem(e, id);
            }
            
            void rmvComponent(const ze::entity_t e, ze::ComponentId id) {
                this->component.erase(e, id);
                this->system.rmvFromSystem(e, id);
            }

            template<typename T>
            T& getComponent(const ze::entity_t e, const ze::ComponentId id) {
                return this->component.at<T>(e, id);
            }

            ze::transform_t& getTransform(const ze::entity_t e) {
                return this->component.getTransform(e);
            }

            const std::unordered_set<ze::entity_t>* getEntitiesFromSystem(const ze::ComponentId id) {
                return this->system.getEntitiesFromSystem(id);
            }
            
            std::pair<ze::entity_t, bool> checkCollision(const ze::entity_t e) {
                std::pair<ze::entity_t, bool> r{0, false};
                const Rectangle eRect = this->component.at<ze::obstacle_t>(e, ze::ObstacleId).rect;                
                for (const ze::entity_t otherEntity : *this->system.getEntitiesFromSystem(ze::ObstacleId))  {                    
                    if (
                        otherEntity != e && CheckCollisionRecs(eRect, this->component.at<ze::obstacle_t>(otherEntity, ze::ObstacleId).rect)
                    ) {
                        r.first = otherEntity;
                        r.second = true;
                        return r;
                    }
                }
                return r;
            }

            std::pair<ze::entity_t, bool> CheckCollisionBox(
                const Rectangle& rect,
                const ze::ComponentId group
            ) { 
                std::pair<ze::entity_t, bool> pair = {0, false};
                for (const ze::entity_t e : *this->system.getEntitiesFromSystem(group)) {
                    ze::transform_t& t = this->getTransform(e);
                    if (CheckCollisionRecs(rect, t.rect)) {
                        pair.first = e;
                        pair.second = true;
                        return pair;
                    }
                }
                return pair;
            }

            void clear() {
                this->shouldClearAllEntities = true;                
            }

            void update(float dt) {
                this->system.update(dt);

                if (this->shouldClearAllEntities) {
                    this->shouldClearAllEntities = false;
                    this->entitiesToDestroy = std::queue<ze::entity_t>();
                    for (auto& pair : this->camera) {
                        pair.second.clear();
                    }
                    this->entity.clear();
                    this->component.clear();
                    this->system.clear();
                }

                while (this->entitiesToDestroy.empty() == false) {
                    const ze::entity_t e = this->entitiesToDestroy.front();
                    this->entitiesToDestroy.pop();
                    this->rmvFromCamera(e);
                    this->entity.entityDestroy(e);
                    this->component.entityDestroy(e);
                    this->system.entityDestroy(e);
                }
            }
            
            void draw() {
                const Rectangle rect = this->component.getTransform(ze::globals::playerEntity).rect;
                const Vector2 offset = { 
                    rect.x + rect.width / 2.f - ZE_SCREEN_WIDTH / 2.f,
                    rect.y + rect.height / 2.f - ZE_SCREEN_HEIGHT / 2.f
			    };
                // zindex and ysort camera
                for (auto& pair : this->camera) {
                    for (auto& p : pair.second) {
                        const ze::transform_t& t = this->component.getTransform(p.second);
                        p.first = t.rect.y + t.rect.height / 2.0f;
                    }
                    std::sort(pair.second.begin(), pair.second.end());
                    for (const auto& p : pair.second) {
                        ze::transform_t& t = this->component.getTransform(p.second);
                        t.rect.x -= offset.x;
                        t.rect.y -= offset.y;
                        this->system.draw(p.second);
                        t.rect.x += offset.x;
                        t.rect.y += offset.y;
                    }
                }
            }

    };

    inline ze::ECS gEcs{};
    
} // namespace ze




#endif