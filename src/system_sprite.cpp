#include "system.h"
#include "ecs.h"
#include "util.h"


void ze::SpriteSystem::update(const float dt) {

}


void ze::SpriteSystem::draw(const ze::entity e) {
	const ze::transform_t& t = ze::gEcs.get_transform(e);
	const ze::sprite_t& s = ze::gEcs.getComponent<ze::sprite_t>(e);
	DrawTextureV(s.texture, {t.rect.x, t.rect.y}, WHITE);
	if (ZE_DEBUD_MODE) {		
		DrawRectangleLines(t.rect.x , t.rect.y, t.rect.width, t.rect.height, RED);		
	}
}