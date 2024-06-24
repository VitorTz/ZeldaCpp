#ifndef ZELDA_UTIL_HPP
#define ZELDA_UTIL_HPP
#include <raylib.h>
#include <vector>
#include <string>


namespace ze {
    
    unsigned long hash(const char* s);

    void applyHitbox(const Rectangle& src, Rectangle* dest, const Vector2 hitbox);

    void normalize_vec(Vector2* v);

    void swap_vec(Vector2* v);

    void print_vec(Vector2 v);

    void print_rect(const Rectangle& rect);

    std::vector<std::string> getFilesFromDir(const char* dir, const char* suffix);    

} // namespace ze


#endif