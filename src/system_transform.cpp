#include "system.hpp"
#include "ecs.hpp"
#include "util.hpp"


void ze::TransformSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {
        ze::transform_t& t = ze::gEcs.getTransform(e);
        ze::normalize_vec(&t.direction);
        const float distance = dt * t.speed;
        t.lastMovement.x = distance * t.direction.x;
        t.lastMovement.y = distance * t.direction.y;
        t.rect.x += t.lastMovement.x;
        t.rect.y += t.lastMovement.y;
    }
}


void ze::TransformSystem::draw(const ze::entity_t e) {
    
}