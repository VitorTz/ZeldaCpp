#include "system.hpp"
#include "ecs.hpp"
#include "globals.hpp"
#include "util.hpp"


void ze::ObstacleSystem::update(const float dt) {
    for (const ze::entity_t e : this->entities) {
        const ze::transform_t& t = ze::gEcs.getTransform(e);
        ze::obstacle_t& o = ze::gEcs.getComponent<ze::obstacle_t>(e);        
        o.rect.width = t.size.x * o.hitbox.x;
        o.rect.height = t.size.y * o.hitbox.y;
        o.rect.x = t.pos.x + ((t.size.x - o.rect.width) / 2.0f);
        o.rect.y = t.pos.y + ((t.size.y - o.rect.height) / 2.0f);
    }
}


void ze::ObstacleSystem::draw(const ze::entity_t e) {
    const ze::obstacle_t& obstacle = ze::gEcs.getComponent<ze::obstacle_t>(e);
    const ze::transform_t& t = ze::gEcs.getTransform(e);
    const Vector2 offset = ze::globals::camera_offset;    
    DrawRectangleLines(
        obstacle.rect.x - offset.x, 
        obstacle.rect.y - offset.y, 
        obstacle.rect.width,
        obstacle.rect.height,
        RED
    );    
    DrawRectangleLines(
        t.pos.x - offset.x, 
        t.pos.y - offset.y, 
        t.size.x,
        t.size.y,
        BLUE
    );    
}