#include "system.h"
#include "ecs.h"
#include <string>


void ze::SpriteSystem::update(const float dt) {

}


void ze::SpriteSystem::draw(const ze::Entity e) {
	const ze::transform_t& t = ze::gEcs.get_transform(e);
	const ze::sprite_t& s = ze::gEcs.getComponent<ze::sprite_t>(e);
	DrawTextureV(s.texture, t.pos, WHITE);	
}