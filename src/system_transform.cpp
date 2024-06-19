#include "system.h"
#include "ecs.h"
#include "util.h"


void ze::TransformSystem::update(const float dt) {
	for (const ze::Entity e : this->entities) {
		ze::transform_t& t = ze::gEcs.get_transform(e);
		const float distance = t.speed * dt;
		ze::normalize_vec(&t.direction);
		t.lastMovement.x = distance * t.direction.x;
		t.lastMovement.y = distance * t.direction.y;
		t.pos.x += t.lastMovement.x;
		t.pos.y += t.lastMovement.y;
	}
}


void ze::TransformSystem::draw(const ze::Entity e) {

}