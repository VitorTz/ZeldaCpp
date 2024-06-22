#ifndef ZELDA_SYSTEM_MANAGER_HPP
#define ZELDA_SYSTEM_MANAGER_HPP
#include <array>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include "types.hpp"
#include "component.hpp"
#include "system.hpp"


namespace ze {


    class SystemManager {

        private:
            std::array<std::unique_ptr<ze::System>, ZE_NUM_COMPONENTS> systems;            
            std::unordered_map<ze::entity_t, std::unordered_set<ze::ComponentId>> systemsByEntity{};
        
        public:
            SystemManager();
            void addToSystem(ze::entity_t e, ze::ComponentId id);
            void rmvFromSystem(ze::entity_t e, ze::ComponentId id);
            void entityDestroy(ze::entity_t e);            
            void update(float dt);
            void draw(ze::entity_t e);
            void clear();
            ze::System* getSystem(ze::ComponentId id);
            const std::unordered_set<ze::entity_t>* getEntitiesFromSystem(ze::ComponentId id);

    };


}


#endif