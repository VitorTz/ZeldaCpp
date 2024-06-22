#include "util.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include "constants.hpp"
#include "texture_pool.hpp"
#include "globals.hpp"


unsigned long ze::hash(const char* s) {
    unsigned long hash = 5381;
    int i = 0;
    while (s[i] != '\0') {
        int c = s[i];
        hash = ((hash << 5) + hash) + c;
        i++;
    }
    return hash;
}


void ze::applyHitbox(
    const Rectangle& src,
    Rectangle* dest,
    const Vector2 hitbox
) {
    dest->width = src.width * hitbox.x;
    dest->height = src.height * hitbox.y;
    dest->x = src.x + ((src.width - dest->width) / 2.f);
    dest->y = src.y + ((src.height - dest->height) / 2.f);
}


void ze::normalize_vec(Vector2* v) {
    const float m = std::sqrt(v->x * v->x + v->y * v->y);
    if (m > 1) {
        v->x /= m;
        v->y /= m;
    }
}


std::vector<std::string> ze::getFilesFromDir(
    const char* file_name,
    const char* extension
) {
    std::vector<std::string> v;
    for (const auto& p : std::filesystem::directory_iterator(file_name)) {
        const std::filesystem::path path = p.path();        
        if (*path.extension().c_str() == *extension) {
            v.push_back(path.string());
        }
    }
    return v;
}
