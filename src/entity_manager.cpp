#include "entity_manager.hpp"
#include "constants.hpp"
#include <cassert>


ze::EntityManager::EntityManager() {
    for (ze::entity_t e = 0; e < ZE_MAX_ENTITIES; e++) {
        this->queue.push(e);
    }
}


ze::entity_t ze::EntityManager::entityCreate() {
    assert(this->mSize < ZE_MAX_ENTITIES);
    const ze::entity_t e = this->queue.front();
    this->queue.pop();
    this->mSize++;
    return e;
}


void ze::EntityManager::entityDestroy(const ze::entity_t e) {
    this->queue.push(e);
    this->mSize--;
}


void ze::EntityManager::clear() {
    this->queue = std::queue<ze::entity_t>();
    this->mSize = 0;
    for (ze::entity_t e = 0; e < ZE_MAX_ENTITIES; e++) {
        this->queue.push(e);
    }
}


std::size_t ze::EntityManager::size() const {
    return this->mSize;
}