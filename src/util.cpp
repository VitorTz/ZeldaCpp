#include "util.h"


unsigned long ze::hash_func(const char* s) {    
    unsigned long hash = 5381;    
    int i = 0;
    while (s[i] != '\0') {
        int c = s[i];
        hash = ((hash << 5) + hash) + c;
        i++;
    }    
    return hash;
}