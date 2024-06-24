#ifndef ZELDA_ECS_HPP
#define ZELDA_ECS_HPP
#include <algorithm>
#include <vector>
#include <map>
#include "entity_manager.hpp"
#include "component_manager.hpp"
#include "system_manager.hpp"
#include "globals.hpp"
#include "util.hpp"


namespace ze {
    

    class ECS {

        private:
            ze::EntityManager entity;
            ze::ComponentManager component;
            ze::SystemManager system;
        
        private:
            std::map<ze::zindex_t, std::vector<std::pair<float, ze::entity_t>>> camera;
            std::queue<ze::entity_t> entitiesToDestroy;
            bool isOnCamera[ZE_MAX_ENTITIES];
            bool should_clear_all_entities = false;
        
        public:
            ECS() {                
                for (ze::zindex_t i = ZE_MIN_ZINDEX; i <= ZE_MAX_ZINDEX; i++) {
                    this->camera.insert({i, {}});
                    this->camera[i].reserve(ZE_MAX_ENTITIES);
                }
            }

            void submitToCamera(const ze::entity_t e, const ze::zindex_t zindex) {
                if (isOnCamera[e] == false) {
                    isOnCamera[e] = true;
                    this->camera[zindex].push_back({0.0f, e});
                }
            }

            void rmvFromCamera(const ze::entity_t e) {
                if (isOnCamera[e] == false) {
                    return;
                } 
                isOnCamera[e] = false;
                const ze::zindex_t z = this->component.getTransform(e).zindex;
                std::vector<std::pair<float, ze::entity_t>>& v = this->camera[z];
                for (std::size_t i = 0; i < v.size(); i++) {
                    if (v[i].second == e) {
                        v.erase(v.begin() + i);
                        return;
                    }
                }
            }

            ze::entity_t entityCreate(const ze::zindex_t zindex, const bool isOnCamera) {
                const ze::entity_t e = this->entity.entityCreate();
                this->component.insert<ze::transform_t>(e, ze::transform_t{.zindex = zindex});
                this->system.insert<ze::transform_t>(e);
                if (isOnCamera) this->submitToCamera(e, zindex);                
                return e;
            }

            void entityDestroy(const ze::entity_t e) {
                this->entitiesToDestroy.push(e);
            }

            template<typename T>
            void insertComponent(const ze::entity_t e, T c) {
                this->component.insert<T>(e, std::move(c));
                this->system.insert<T>(e);
            }

            template<typename T>
            T& getComponent(const ze::entity_t e) {
                return this->component.at<T>(e);
            }

            template<typename T>
            void eraseComponent(const ze::entity_t e) {
                this->component.erase<T>(e);
                this->system.erase<T>(e);
            }

            template<typename T>
            const std::unordered_set<ze::entity_t>* getEntitiesBySystem() {
                return this->system.getEntitiesBySystem<T>();
            };

            std::pair<ze::entity_t, bool> checkCollision(const ze::entity_t e, const Rectangle rect) {
                std::pair<ze::entity_t, bool> pair{0, false};
                for (const ze::entity_t otherEntity : *this->system.getEntitiesBySystem<ze::obstacle_t>()) {
                    const ze::obstacle_t& o = this->component.at<ze::obstacle_t>(otherEntity);
                    if (e != otherEntity && CheckCollisionRecs(rect, o.rect)) {
                        pair.first = otherEntity;
                        pair.second = true;
                        break;
                    }
                }
                return pair;
            }

            ze::transform_t& getTransform(const ze::entity_t e) {
                return this->component.getTransform(e);
            }

            void clear() {
                this->should_clear_all_entities = true;
            }

            void update(float dt) {
                this->system.update(dt);
                for (auto& pair : this->camera) {
                    for (std::pair<float, ze::entity_t>& p : pair.second) {
                        const ze::transform_t& t = this->component.getTransform(p.second);
                        p.first = t.pos.y + t.size.y / 2.0f;
                    }
                    std::sort(pair.second.begin(), pair.second.end());
                }
            }

            void draw() {
                const Vector2 offset = ze::globals::camera_offset;

                for (auto& pair : this->camera) {
                    for (auto& p : pair.second) {
                        ze::transform_t& t = this->component.getTransform(p.second);
                        t.pos.x -= offset.x;
                        t.pos.y -= offset.y;
                        this->system.draw(p.second);
                        t.pos.x += offset.x;
                        t.pos.y += offset.y;
                    }
                }

                if (this->should_clear_all_entities) {
                    this->should_clear_all_entities = false;
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

                if (ZE_DEBUG_MODE) {                    
                    ze::ObstacleSystem* obstacle = (ze::ObstacleSystem*) this->system.getSystem<ze::obstacle_t>();
                    for (const ze::entity_t e : obstacle->entities) {
                        obstacle->draw(e);
                    }
                    this->system.getSystem<ze::player_t>()->draw(0);
                }

            }

    };

    inline ze::ECS gEcs{};

} // namespace ze



#endif