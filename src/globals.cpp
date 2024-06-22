#include "globals.hpp"


void ze::globals::init() {
    ze::globals::font = LoadFontEx("assets/font/The-Wild-Breath-of-Zelda.ttf", 52, 0, 255);    
}


void ze::globals::close() {
    UnloadFont(ze::globals::font);
}