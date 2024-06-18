#ifndef ZELDA_GLOBALS_H
#define ZELDA_GLOBALS_H
#include <raylib.h>
#include "constants.h"


namespace ze {


    namespace globals {
        
        extern Font gFont;

        void init();
        void close();

        Font get_font();
        
    } // namespace globals    
    
} // namespace ze



#endif