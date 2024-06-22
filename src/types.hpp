#ifndef ZELDA_TYPES_HPP
#define ZELDA_TYPES_HPP
#include <cstdint>


namespace ze {

    typedef std::uint32_t entity_t;
    typedef std::uint8_t zindex_t;

    enum TileType {
        Grass,
        Block
    };

    enum Weapon {
        Axe,
        Lance,
        Rapier,
        Sai,
        Sword
    };

    typedef struct tile {
        ze::entity_t entity;        
        int id;
        ze::TileType type;
    } tile_t;

    enum SceneId {
        TitleScreenSceneId,
        LevelSceneId
    };

    enum AnimationSpeed {
        Slow = 4,
        Normal = 6,
        Fast = 8
    }; 
    
} // namespace ze



#endif