#ifndef ZELDA_SYSTEM_MANAGER_HPP
#define ZELDA_SYSTEM_MANAGER_HPP
#include <unordered_map>
#include <memory>
#include "player.hpp"
#include "constants.hpp"
#include "component_type.hpp"
#include "system.hpp"


namespace ze {

    class SystemManager {

        private:
            std::unordered_map<ze::component_t, std::unique_ptr<ze::System>> systemMap;
            std::unordered_map<ze::entity_t, std::unordered_set<ze::component_t>> systemByEntity{};
        
        public:
            SystemManager() {
                this->systemMap.emplace(ze::getType<ze::transform_t>(), std::make_unique<ze::TransformSystem>());
                this->systemMap.emplace(ze::getType<ze::sprite_t>(), std::make_unique<ze::SpriteSystem>());
                this->systemMap.emplace(ze::getType<ze::sprite_animation_t>(), std::make_unique<ze::SpriteAnimationSystem>());
                this->systemMap.emplace(ze::getType<ze::obstacle_t>(), std::make_unique<ze::ObstacleSystem>());
                assert(this->systemMap.size() == ZE_NUM_COMPONENTS);
                this->systemMap.emplace(ze::getType<ze::player_t>(), std::make_unique<ze::PlayerSystem>());

                this->systemByEntity.reserve(ZE_MAX_ENTITIES);
                for (ze::entity_t e = 0; e < ZE_MAX_ENTITIES; e++) {
                    this->systemByEntity.insert({e, {}});
                }
            }
            
            template<typename T>
            void insert(const ze::entity_t e) {                
                const ze::component_t id = ze::getType<T>();
                this->systemByEntity[e].insert(id);
                this->systemMap[id]->entities.insert(e);
            }
            
            template<typename T>
            void erase(const ze::entity_t e) {
                const ze::component_t id = ze::getType<T>();
                this->systemByEntity[e].erase(id);
                this->systemMap[id]->entities.erase(e);                
            }

            void entityDestroy(const ze::entity_t e) {
                for (auto& pair : this->systemMap) {
                    pair.second->entities.erase(e);
                }
            }

            void update(const float dt) {
                for (auto& pair : this->systemMap) {
                    pair.second->update(dt);
                }   
            }

            template<typename T>
            const std::unordered_set<ze::entity_t>* getEntitiesBySystem() {
                return &this->systemMap[ze::getType<T>()]->entities;
            };

            template<typename T>
            ze::System* getSystem() {
                return this->systemMap[ze::getType<T>()].get();
            }

            void draw(const ze::entity_t e) {
                for (const ze::component_t id : this->systemByEntity[e]) {                    
                    this->systemMap[id]->draw(e);
                }
            }

            void clear() {
                for (auto& pair : this->systemMap) {
                    pair.second->entities.clear();
                }
                for (auto& pair : this->systemByEntity) {
                    pair.second.clear();
                }
            }

    };
    
} // namespace ze


#endif