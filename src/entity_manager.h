#pragma once
#include <queue>
#include "constants.h"
#include "types.h"


namespace ze {

	class EntityManager {

	private:
		std::queue<ze::entity> queue;
		std::size_t mSize = 0;

	public:
		EntityManager();
		ze::entity entityCreate();
		void entityDestroy(ze::entity e);
		void clear();
		std::size_t size() const;

	};


}