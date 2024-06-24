#ifndef ZELDA_COMPONENT_MANAGER_HPP
#define ZELDA_COMPONENT_MANAGER_HPP
#include <memory>
#include "component_array.hpp"
#include "component_type.hpp"


namespace ze {


    class ComponentManager {

        private:
            std::unordered_map<ze::component_t, std::unique_ptr<ze::IComponentArray>> componentMap;
            ze::ComponentArray<ze::transform_t>* transform;
        
        private:
            template<typename T>
            ze::ComponentArray<T>* getArray() {
                return dynamic_cast<ze::ComponentArray<T>*>(this->componentMap[ze::getType<T>()].get());
            }
        
        public:
            ComponentManager() {
                this->componentMap.emplace(ze::getType<ze::transform_t>(), std::make_unique<ze::ComponentArray<ze::transform_t>>());
                this->componentMap.emplace(ze::getType<ze::sprite_t>(), std::make_unique<ze::ComponentArray<ze::sprite_t>>());
                this->componentMap.emplace(ze::getType<ze::sprite_animation_t>(), std::make_unique<ze::ComponentArray<ze::sprite_animation_t>>());
                this->componentMap.emplace(ze::getType<ze::obstacle_t>(), std::make_unique<ze::ComponentArray<ze::obstacle_t>>());
                assert(this->componentMap.size() == ZE_NUM_COMPONENTS);
                this->transform = this->getArray<ze::transform_t>();
            }
            template<typename T>
            void insert(const ze::entity_t e, T c) {
                this->getArray<T>()->insert(e, std::move(c));
            }

            template<typename T>
            void erase(const ze::entity_t e) {
                this->componentMap[ze::getType<T>()]->erase(e);
            }

            template<typename T>
            T& at(const ze::entity_t e) {
                return this->getArray<T>()->at(e);
            }

            ze::transform_t& getTransform(const ze::entity_t e) {
                return this->transform->at(e);
            }

            void entityDestroy(const ze::entity_t e) {
                for (auto& pair : this->componentMap) {
                    pair.second->erase(e);
                }
            } 

            void clear() {
                for (auto& pair : this->componentMap) {
                    pair.second->clear();
                }
            }

    };
    
    

} // namespace ze


#endif