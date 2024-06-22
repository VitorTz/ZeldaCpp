#include "util.h"
#include "texture_pool.h"


void ze::normalize_vec(Vector2* v) {
	const float m = std::sqrt(v->x * v->x + v->y * v->y);
	if (m > 1) {
		v->x /= m;
		v->y /= m;
	}
}


unsigned long ze::hash_f(const char* s) {
    unsigned long hash = 5381;
    int i = 0;
    while (s[i] != '\0') {
        int c = s[i];
        hash = ((hash << 5) + hash) + c;
        i++;
    }
    return hash;
}


void ze::print_vec(const Vector2 v) {
    printf("Vec(%.2f, %.2f)\n", v.x, v.y);
}


void ze::print_rect(const Rectangle& r) {
    printf("Rect(%.2f, %.2f, %.2f, %.2f)\n", r.x, r.y, r.width, r.height);
}


void ze::quit_game() {
    ze::gTexturePool.clear();
}