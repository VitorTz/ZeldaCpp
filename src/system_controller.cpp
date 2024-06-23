#include "system.hpp"
#include "ecs.hpp"


void ze::ControllerSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {
        ze::transform_t& t = ze::gEcs.getTransform(e);
        t.direction.x = t.direction.y = 0.0f;
        if (IsKeyDown(KEY_LEFT)) {
            t.direction.x = -1.0f;
            t.directionChar[1] = 'l';
        } else if (IsKeyDown(KEY_RIGHT)) {
            t.direction.x = 1.0f;
            t.directionChar[1] = 'r';
        }

        if (IsKeyDown(KEY_UP)) {
            t.direction.y = -1.0f;
            t.directionChar[1] = 'u';
        } else if (IsKeyDown(KEY_DOWN)) {
            t.direction.y = 1.0f;
            t.directionChar[1] = 'd';
        }
        t.directionChar[0] = t.direction.x == 0.0f && t.direction.y == 0.0f ? 'i' : 'm';
    }
}


void ze::ControllerSystem::draw(const ze::entity_t e) {

}