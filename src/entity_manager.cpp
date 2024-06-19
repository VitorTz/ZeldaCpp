#include <cassert>
#include "entity_manager.h"


ze::EntityManager::EntityManager() {
	for (ze::Entity e = 0; e < ZE_MAX_ENTITIES; e++) {
		this->queue.push(e);
	}	
}


ze::Entity ze::EntityManager::entityCreate() {
	assert(this->mSize < ZE_MAX_ENTITIES);
	const ze::Entity e = this->queue.front();
	this->queue.pop();
	this->mSize++;
	return e;
}


void ze::EntityManager::entityDestroy(const ze::Entity e) {
	this->queue.push(e);
	this->mSize--;
}


void ze::EntityManager::clear() {
	this->queue = std::queue<ze::Entity>();
	for (ze::Entity e = 0; e < ZE_MAX_ENTITIES; e++) {
		this->queue.push(e);
	}
	this->mSize = 0;
}


std::size_t ze::EntityManager::size() const {
	return this->mSize;
}