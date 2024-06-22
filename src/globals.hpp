#ifndef ZELDA_GLOBALS_HPP
#define ZELDA_GLOBALS_HPP
#include <raylib.h>
#include <random>
#include "types.hpp"


namespace ze {

    namespace globals {

        inline Font font;
        inline ze::entity_t playerEntity;
        inline std::default_random_engine generator;

        void init();
        void close();

    }

    
} // namespace ze



#endif