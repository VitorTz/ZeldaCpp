#include "system.h"
#include "ecs.h"
#include "util.h"


void ze::PlayerSystem::update(const float dt) {
	for (const ze::entity e : this->entities) {
		ze::transform_t& t = ze::gEcs.get_transform(e);		
		if (ze::gEcs.checkCollision(e, ze::gEcs.getComponent<ze::obstacle_t>(e).rect) == true) {
			t.rect.x -= t.lastMovement.x;
			t.rect.y -= t.lastMovement.y;
			t.lastMovement = { 0.0f, 0.0f };
		}
	}
}


void ze::PlayerSystem::draw(const ze::entity e) {

}