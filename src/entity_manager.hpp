#ifndef ZELDA_ENTITY_MANAGER_HPP
#define ZELDA_ENTITY_MANAGER_HPP
#include <queue>
#include "types.hpp"


namespace ze {

    class EntityManager {

        private:
            std::queue<ze::entity_t> queue;
            std::size_t mSize = 0;
        
        public:
            EntityManager();
            ze::entity_t entityCreate();
            void entityDestroy(ze::entity_t e);
            void clear();
            std::size_t size() const;

    };
    
} // namespace ze



#endif