#include "system.hpp"
#include "ecs.hpp"


void ze::SpriteSystem::update(const float dt) {

}


void ze::SpriteSystem::draw(const ze::entity_t e) {
    const ze::transform_t& t = ze::gEcs.getTransform(e);
    const ze::sprite_t& s = ze::gEcs.getComponent<ze::sprite_t>(e);
    DrawTextureV(s.texture, t.pos, WHITE);
}