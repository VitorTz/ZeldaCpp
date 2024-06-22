#ifndef ZELDA_UTIL_HPP
#define ZELDA_UTIL_HPP
#include <raylib.h>
#include <vector>
#include <filesystem>
#include <string>
#include "types.hpp"


namespace ze {
    
    unsigned long hash(const char* s);

    void applyHitbox(const Rectangle& src, Rectangle* dest, const Vector2 hitbox);

    void normalize_vec(Vector2* v);

    std::vector<std::string> getFilesFromDir(const char* dir, const char* suffix);    

} // namespace ze


#endif