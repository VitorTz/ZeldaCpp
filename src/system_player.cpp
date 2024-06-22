#include "system.h"
#include "ecs.h"
#include "util.h"


void ze::PlayerSystem::update(const float dt) {
	for (const ze::entity e : this->entities) {
		ze::player_t& p = ze::gEcs.getComponent<ze::player_t>(e);
		ze::transform_t& t = ze::gEcs.get_transform(e);		
		ze::sprite_animation_t& s = ze::gEcs.getComponent<ze::sprite_animation_t>(e);
		
		// check movement
		if (ze::gEcs.checkCollision(e, ze::gEcs.getComponent<ze::obstacle_t>(e).rect) == true) {
			t.rect.x -= t.lastMovement.x;
			t.rect.y -= t.lastMovement.y;
			t.lastMovement = { 0.0f, 0.0f };
		}

		// check animation
		if (p.action != p.lastAction) {
			switch (p.action) {
				case ze::Down:
					s.changeTexture(ASSETS_PATH "graphics/player/down.png", ZE_TILE_SIZE);
					break;
				case ze::Right:
					s.changeTexture(ASSETS_PATH "graphics/player/right.png", ZE_TILE_SIZE);
					break;
				case ze::Up:
					s.changeTexture(ASSETS_PATH "graphics/player/up.png", ZE_TILE_SIZE);
					break;
				case ze::Left:
					s.changeTexture(ASSETS_PATH "graphics/player/left.png", ZE_TILE_SIZE);
					break;
				case ze::DownIdle:
					s.changeTexture(ASSETS_PATH "graphics/player/idle_down.png", ZE_TILE_SIZE);
					break;
				case ze::LeftIdle:
					s.changeTexture(ASSETS_PATH "graphics/player/idle_left.png", ZE_TILE_SIZE);
					break;
				case ze::RightIdle:
					s.changeTexture(ASSETS_PATH "graphics/player/idle_right.png", ZE_TILE_SIZE);
					break;
				case ze::UpIdle:
					s.changeTexture(ASSETS_PATH "graphics/player/idle_up.png", ZE_TILE_SIZE);
					break;
				case ze::LeftAttack:
					s.changeTexture(ASSETS_PATH "graphics/player/attack_left.png", ZE_TILE_SIZE);
					break;
				case ze::RightAttack:
					s.changeTexture(ASSETS_PATH "graphics/player/attack_right.png", ZE_TILE_SIZE);
					break;
				case ze::UpAttack:
					s.changeTexture(ASSETS_PATH "graphics/player/attack_up.png", ZE_TILE_SIZE);
					break;
				case ze::DownAttack:
					s.changeTexture(ASSETS_PATH "graphics/player/attack_down.png", ZE_TILE_SIZE);
					break;
				default:
					break;
			}
		}
		p.lastAction = p.action;
	}
}


void ze::PlayerSystem::draw(const ze::entity e) {

}