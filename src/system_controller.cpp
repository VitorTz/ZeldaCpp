#include "system.h"
#include "ecs.h"


void ze::ControllerSystem::update(const float dt) {
	for (const ze::entity e : this->entities) {
		ze::transform_t& t = ze::gEcs.get_transform(e);
		t.direction = { 0.0f, 0.0f };
		if (IsKeyDown(KEY_LEFT)) {
			t.direction.x = -1;
		}
		else if (IsKeyDown(KEY_RIGHT)) {
			t.direction.x = 1;
		}
		if (IsKeyDown(KEY_UP)) {
			t.direction.y = -1;
		}
		else if (IsKeyDown(KEY_DOWN)) {
			t.direction.y = 1;
		}
	}
}


void ze::ControllerSystem::draw(const ze::entity e) {

}