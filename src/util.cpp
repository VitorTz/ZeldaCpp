#include "util.h"


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
