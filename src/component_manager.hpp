#ifndef ZELDA_COMPONENT_MANAGER_HPP
#define ZELDA_COMPONENT_MANAGER_HPP
#include <memory>
#include <cassert>
#include "component_array.hpp"


namespace ze {


    class ComponentManager {


        private:
            std::array<std::unique_ptr<ze::IComponentArray>, ZE_NUM_COMPONENTS> components;
            ze::ComponentArray<ze::transform_t>* transform;
            std::size_t mSize = 0;

        public:
            ComponentManager(

            ) : components(
                {
                    std::make_unique<ze::ComponentArray<ze::sprite_t>>(),
                    std::make_unique<ze::ComponentArray<ze::transform_t>>(),
                    std::make_unique<ze::ComponentArray<ze::obstacle_t>>(),
                    std::make_unique<ze::ComponentArray<ze::controller_t>>(),                    
                    std::make_unique<ze::ComponentArray<ze::animation_t>>(),
                    std::make_unique<ze::ComponentArray<ze::player_t>>()
                }
            ) {
                this->transform = static_cast<ze::ComponentArray<ze::transform_t>*>(
                    this->components[ze::TransformId].get()
                );
                assert(this->components.size() == ZE_NUM_COMPONENTS);
            }
            template<typename T>
            void insert(const ze::entity_t e, T c, const ze::ComponentId id) {
                ze::ComponentArray<T>* arr = static_cast<ze::ComponentArray<T>*>(this->components[id].get());
                arr->insert(e, std::move(c));
                this->mSize++;
            }
            
            template<typename T>
            T& at(const ze::entity_t e, const ze::ComponentId id) {
                ze::ComponentArray<T>* arr = static_cast<ze::ComponentArray<T>*>(this->components[id].get());
                return arr->at(e);
            }

            ze::transform_t& getTransform(const ze::entity_t e) {
                return this->at<ze::transform_t>(e, ze::TransformId);
            }

            void erase(const ze::entity_t e, ze::ComponentId id) {
                const bool removed = this->components[id]->erase(e);
                this->mSize -= removed ? 1 : 0;
            }
            void entityDestroy(const ze::entity_t e) {
                for (auto& c : components) {
                    c->erase(e);
                }
            }
            void clear() {
                for (auto& c : components) {
                    c->clear();
                }
            }
    };

    
} // namespace ze




#endif