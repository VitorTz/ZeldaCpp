#include "system.hpp"
#include "ecs.hpp"


void ze::ControllerSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {
        ze::transform_t& t = ze::gEcs.getTransform(e);
        t.direction.x = 0.0f;
        t.direction.y = 0.0f;
        if (IsKeyDown(KEY_LEFT)) {
            t.direction.x = -1.0f;
        } else if (IsKeyDown(KEY_RIGHT)) {
            t.direction.x = 1.0f;
        }

        if (IsKeyDown(KEY_UP)) {
            t.direction.y = -1.0f;
        } else if (IsKeyDown(KEY_DOWN)) {
            t.direction.y = 1.0f;
        }
    }
}


void ze::ControllerSystem::draw(const ze::entity_t e) {

}