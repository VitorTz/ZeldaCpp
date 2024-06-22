#include "system.hpp"
#include "ecs.hpp"
#include <iostream>


void ze::AnimationSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {
        ze::animation_t& a = ze::gEcs.getComponent<ze::animation_t>(e, ze::AnimationId);
        a.frame_counter++;        
		if (a.frame_counter > a.speed) {
			a.frame_counter = 0;
			a.current_frame++;
			if (a.current_frame >= a.max_frames) {
				a.current_frame = 0;
				a.rect.x = 0;
			}
			a.rect.x += a.rect.width;
		}
    }
}


void ze::AnimationSystem::draw(const ze::entity_t e) {
    const ze::transform_t& t = ze::gEcs.getTransform(e);
    const ze::animation_t& a = ze::gEcs.getComponent<ze::animation_t>(e, ze::AnimationId);
    DrawTextureRec(a.texture, a.rect, { t.rect.x, t.rect.y }, WHITE);
}