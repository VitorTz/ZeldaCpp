#ifndef ZELDA_TILE_MAP_HPP
#define ZELDA_TILE_MAP_HPP
#include <unordered_map>
#include <raylib.h>
#include <cstdint>
#include <string>
#include <vector>


namespace ze {

    enum TileType {
        Grass,
        Block
    };

    typedef struct tile {
        Texture2D texture;
        ze::TileType type;
        Vector2 pos;
        std::uint8_t id;
    } tile_t;

    void read_csv(const char* file_name, std::vector<ze::tile_t>* tiles, ze::TileType type);

    const static std::unordered_map<std::uint8_t, const char*> tilePathById = {
        {8, "assets/graphics/grass/grass_1.png"},
        {9, "assets/graphics/grass/grass_2.png"},
        {10, "assets/graphics/grass/grass_3.png"}
    };

    
} // namespace ze



#endif