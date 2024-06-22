#include "system_manager.hpp"
#include "constants.hpp"
#include <cassert>


ze::SystemManager::SystemManager(

) : systems(
    {
        std::make_unique<ze::SpriteSystem>(),
        std::make_unique<ze::TransformSystem>(),
        std::make_unique<ze::ObstacleSystem>(),
        std::make_unique<ze::ControllerSystem>(),        
        std::make_unique<ze::AnimationSystem>(),
        std::make_unique<ze::PlayerSystem>()
    }
) {
    for (ze::entity_t e = 0; e < ZE_MAX_ENTITIES; e++) {
        this->systemsByEntity.insert({e, {}});
    }
    assert(this->systems.size() == ZE_NUM_COMPONENTS);
}


void ze::SystemManager::addToSystem(
    const ze::entity_t e,
    const ze::ComponentId id
) {
    systems[id]->entities.insert(e);
    this->systemsByEntity[e].insert(id);
}


void ze::SystemManager::rmvFromSystem(
    const ze::entity_t e,
    const ze::ComponentId id
) {
    systems[id]->entities.erase(e);    
    this->systemsByEntity[e].erase(id);
}


void ze::SystemManager::entityDestroy(const ze::entity_t e) {
    for (auto& s : systems) {
        s->entities.erase(e);
    }
    this->systemsByEntity[e].clear();
}


void ze::SystemManager::update(const float dt) {
    for (auto& s : this->systems) {
        s->update(dt);
    }
}


void ze::SystemManager::draw(const ze::entity_t e) {
    for (const ze::ComponentId id : this->systemsByEntity[e]) {
        this->systems[id]->draw(e);
    }
}


ze::System* ze::SystemManager::getSystem(const ze::ComponentId id) {
    return this->systems[id].get();
}


void ze::SystemManager::clear() {
    for (auto& s : this->systems) {
        s->entities.clear();
    }
    for (auto& pair : this->systemsByEntity) {
        pair.second.clear();
    }
}


const std::unordered_set<ze::entity_t>* ze::SystemManager::getEntitiesFromSystem(ze::ComponentId id) {
    return &systems[id]->entities;
}