#include "system.hpp"
#include "util.hpp"
#include "ecs.hpp"


void ze::ObstacleSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {
        const ze::transform_t& t = ze::gEcs.getTransform(e);
        ze::obstacle_t& o = ze::gEcs.getComponent<ze::obstacle_t>(e, ze::ObstacleId);
        ze::applyHitbox(t.rect, &o.rect, o.hitbox);
    }
}


void ze::ObstacleSystem::draw(const ze::entity_t e) {
    
}