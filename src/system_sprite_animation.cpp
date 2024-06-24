#include "system.hpp"
#include "ecs.hpp"


void ze::SpriteAnimationSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {
        ze::sprite_animation_t& s = ze::gEcs.getComponent<ze::sprite_animation_t>(e);
        s.frame_counter++;        
		if (s.frame_counter > s.speed) {
			s.frame_counter = 0;
			s.current_frame++;
			if (s.current_frame >= s.max_frames) {
				s.current_frame = 0;
				s.rect.x = 0;
			}
			s.rect.x += s.rect.width;
		}
    }
}


void ze::SpriteAnimationSystem::draw(const ze::entity_t e) {
    const ze::transform_t& t = ze::gEcs.getTransform(e);
    const ze::sprite_animation_t& a = ze::gEcs.getComponent<ze::sprite_animation_t>(e);
    DrawTextureRec(a.texture, a.rect, t.pos, WHITE);
}