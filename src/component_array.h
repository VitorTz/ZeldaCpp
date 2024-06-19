#pragma once
#include <array>
#include <unordered_map>
#include <cassert>
#include "types.h"
#include "constants.h"


namespace ze {


	class IComponentArray {
	
	public:
		virtual ~IComponentArray() = default;
		virtual bool erase(ze::Entity e) = 0;
		virtual void clear() = 0;
		virtual std::size_t size() const = 0;

	};


	template<typename T>
	class ComponentArray : public ze::IComponentArray {

	private:
		std::array<T, ZE_MAX_ENTITIES> arr{};
		std::unordered_map<ze::Entity, std::size_t> entityToIndex;
		std::unordered_map<std::size_t, ze::Entity> indexToEntity;
		std::size_t mSize = 0;

	public:

		ComponentArray() {
			this->entityToIndex.reserve(ZE_MAX_ENTITIES / this->entityToIndex.max_load_factor());
			this->indexToEntity.reserve(ZE_MAX_ENTITIES / this->indexToEntity.max_load_factor());
		}

		void insert(const ze::Entity e, T c) {
			assert(this->entityToIndex.find(e) == this->entityToIndex.end());
			this->entityToIndex[e] = this->mSize;
			this->indexToEntity[this->mSize] = e;
			this->arr[this->mSize++] = c;
		}

		bool erase(const ze::Entity e) override {
			if (this->entityToIndex.find(e) != this->entityToIndex.end()) {
				const std::size_t lastComponentIndex = --this->mSize;
				const std::size_t removedComponentIndex = this->entityToIndex[e];
				const ze::Entity lastEntity = this->entityToIndex[lastComponentIndex];
				this->arr[removedComponentIndex] = this->arr[lastComponentIndex];

				this->entityToIndex[lastEntity] = removedComponentIndex;
				this->indexToEntity[removedComponentIndex] = lastEntity;

				this->entityToIndex.erase(e);
				this->indexToEntity.erase(lastComponentIndex);
				return true;
			}
			return false;
		}

		T& at(const ze::Entity e) {
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


}