#include "system.h"
#include "ecs.h"


void ze::SpriteAnimationSystem::update(const float dt) {
	for (const ze::entity e : this->entities) {		
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


void ze::SpriteAnimationSystem::draw(const ze::entity e) {
	const ze::sprite_animation_t& s = ze::gEcs.getComponent<ze::sprite_animation_t>(e);	
	const ze::transform_t& t = ze::gEcs.get_transform(e);	
	DrawTextureRec(s.texture, s.rect, { t.rect.x, t.rect.y }, WHITE);
}