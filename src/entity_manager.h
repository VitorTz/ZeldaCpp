#pragma once
#include <queue>
#include "constants.h"
#include "types.h"


namespace ze {

	class EntityManager {

	private:
		std::queue<ze::Entity> queue;
		std::size_t mSize = 0;

	public:
		EntityManager();
		ze::Entity entityCreate();
		void entityDestroy(ze::Entity e);
		void clear();
		std::size_t size() const;

	};


}