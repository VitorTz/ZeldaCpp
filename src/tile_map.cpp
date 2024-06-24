#include "texture_pool.hpp"
#include "constants.hpp"
#include "tile_map.hpp"
#include "globals.hpp"
#include <iostream>
#include <fstream>


void ze::read_csv(
    const char* csv,
    std::vector<ze::tile_t>* v,
    const ze::TileType type
) {
    std::ifstream f(csv, std::fstream::in);
    std::string line, num;    

    if (f.is_open() == false) {
        std::cout << "[ERRO AO ABRIR CSV " << line << ']' << '\n';
        ze::gTexturePool.clear();
        ze::globals::close();
        std::exit(EXIT_FAILURE);        
    }

    int i = 0, j = 0;    
    while (std::getline(f, line)) {
        for (const char c : line) {
            if (c == ',') {
                const int id = std::stoi(num);
                if (id != -1) {
                    v->push_back(
                        ze::tile_t{
                            .texture = type != ze::Block ? ze::gTexturePool.load(ze::tilePathById.at(id)) : Texture2D{},
                            .type = type,
                            .pos = {(float) (j * ZE_TILE_SIZE), (float) (i * ZE_TILE_SIZE)},
                            .id = (std::uint8_t) std::stoi(num)
                        }
                    );
                }
                num = "";                
                j++;
            } else {
                num += c;                
            }
        }
        j = 0;
        i++;
    }

    f.close();
}