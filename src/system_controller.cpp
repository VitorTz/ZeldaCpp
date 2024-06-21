#include "system.h"
#include "ecs.h"


void ze::ControllerSystem::update(const float dt) {
	for (const ze::entity e : this->entities) {
		ze::player_t& p = ze::gEcs.getComponent<ze::player_t>(e);
		ze::transform_t& t = ze::gEcs.get_transform(e);
				
		int action = (p.action & 0x80);
		int direction = (p.action & 0x3F);
		
		t.direction = { 0.0f, 0.0f };

		if (IsKeyDown(KEY_LEFT)) {
			t.direction.x = -1.0f;
			direction = ze::Left;
		}
		else if (IsKeyDown(KEY_RIGHT)) {
			t.direction.x = 1.0f;
			direction = ze::Right;
		}
		if (IsKeyDown(KEY_UP)) {
			t.direction.y = -1.0f;
			direction = ze::Up;
		}
		else if (IsKeyDown(KEY_DOWN)) {
			t.direction.y = 1.0f;
			direction = ze::Down;
		}

		int idle = (t.direction.x == 0.0f && t.direction.y == 0.0f) ? ze::Idle : 0;		

		p.action = (ze::Action)(direction + action + idle);
		
	}
}


void ze::ControllerSystem::draw(const ze::entity e) {

}