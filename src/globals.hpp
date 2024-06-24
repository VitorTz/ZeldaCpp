#ifndef ZELDA_GLOBALS_HPP
#define ZELDA_GLOBALS_HPP
#include <raylib.h>


namespace ze {

    namespace globals {

        inline Font font;
        inline Vector2 camera_offset;

        void init();
        void close();
        
    } // namespace globals
    
    
} // namespace ze



#endif