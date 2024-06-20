#include <cassert>
#include "entity_manager.h"


ze::EntityManager::EntityManager() {
	for (ze::entity e = 0; e < ZE_MAX_ENTITIES; e++) {
		this->queue.push(e);
	}	
}


ze::entity ze::EntityManager::entityCreate() {
	assert(this->mSize < ZE_MAX_ENTITIES);
	const ze::entity e = this->queue.front();
	this->queue.pop();
	this->mSize++;
	return e;
}


void ze::EntityManager::entityDestroy(const ze::entity e) {
	this->queue.push(e);
	this->mSize--;
}


void ze::EntityManager::clear() {
	this->queue = std::queue<ze::entity>();
	for (ze::entity e = 0; e < ZE_MAX_ENTITIES; e++) {
		this->queue.push(e);
	}
	this->mSize = 0;
}


std::size_t ze::EntityManager::size() const {
	return this->mSize;
}