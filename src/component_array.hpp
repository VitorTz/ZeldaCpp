#ifndef ZELDA_COMPONENT_ARRAY_HPP
#define ZELDA_COMPONENT_ARRAY_HPP
#include <unordered_map>
#include <array>
#include <cassert>
#include "constants.hpp"
#include "types.hpp"


namespace ze {


    class IComponentArray {

        public:
            virtual ~IComponentArray() = default;
            virtual bool erase(ze::entity_t e) = 0;
            virtual void clear() = 0;
        
    };


    template<typename T>
    class ComponentArray : public ze::IComponentArray {

        private:
            std::array<T, ZE_MAX_ENTITIES> arr{}; 
            std::unordered_map<ze::entity_t, std::size_t> entityToIndex{};
            std::unordered_map<std::size_t, ze::entity_t> indexToEntity{};
            std::size_t mSize = 0;

        public:
            void insert(const ze::entity_t e, T c) {
                assert(this->entityToIndex.find(e) == this->entityToIndex.end());
                this->entityToIndex[e] = this->mSize;
                this->indexToEntity[this->mSize] = e;
                this->arr[this->mSize++] = c;
            }
            
            bool erase(const ze::entity_t e) override {
                if (this->entityToIndex.find(e) == this->entityToIndex.end()) {
                    return false;
                }
                const std::size_t lastComponentIndex = --this->mSize;
                const std::size_t removedComponentIndex = this->entityToIndex[e];
                const ze::entity_t lastEntity = this->indexToEntity[lastComponentIndex];

                this->arr[removedComponentIndex] = this->arr[lastComponentIndex];

                this->entityToIndex[lastEntity] = removedComponentIndex;
                this->indexToEntity[removedComponentIndex] = lastEntity;
                
                this->entityToIndex.erase(e);
                this->indexToEntity.erase(lastComponentIndex);
                return true;
            }

            T& at(const ze::entity_t e) {
                assert(this->entityToIndex.find(e) != this->entityToIndex.end());
                return this->arr[this->entityToIndex[e]];
            }
            
            void clear() override {
                this->entityToIndex.clear();
                this->indexToEntity.clear();
                this->mSize = 0;
            }
            std::size_t size() const {
                return this->mSize;
            }

    };
    
} // namespace ze



#endif