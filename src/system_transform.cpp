#include <cmath>
#include "system.hpp"
#include "ecs.hpp"


void ze::TransformSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {
        ze::transform_t& t = ze::gEcs.getTransform(e);
        const float m = std::sqrt(t.direction.x * t.direction.x + t.direction.y * t.direction.y);
        if (m > 1) {
            t.direction.x /= m;
            t.direction.y /= m;
        }
        const float distance = dt * t.speed;        
        t.pos.x += t.direction.x * distance;
        t.pos.y += t.direction.y * distance;
    }
}


void ze::TransformSystem::draw([[maybe_unused]] const ze::entity_t e) {

}