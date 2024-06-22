#include "system.h"
#include "ecs.h"


void ze::ObstacleSystem::update(const float dt) {
	for (const ze::entity e : this->entities) {
		const ze::transform_t& t = ze::gEcs.get_transform(e);
		ze::obstacle_t& o = ze::gEcs.getComponent<ze::obstacle_t>(e);
		o.rect.width = t.rect.width * o.hitbox.x;
		o.rect.height = t.rect.height * o.hitbox.y;		
		o.rect.x = t.rect.x + t.rect.width / 2.f - o.rect.width / 2.f;
		o.rect.y = t.rect.y + t.rect.height / 2.f - o.rect.height / 2.f;
	}
}


void ze::ObstacleSystem::draw(const ze::entity e) {

}