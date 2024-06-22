#ifndef ZELDA_CONSTANTS_H
#define ZELDA_CONSTANTS_H
#include "types.hpp"



#define ZE_SCREEN_WIDTH (1280)
#define ZE_SCREEN_HEIGHT (720)
#define ZE_SCREEN_CENTERX (ZE_SCREEN_WIDTH / 2.0f)
#define ZE_SCREEN_CENTERY (ZE_SCREEN_HEIGHT / 2.0f)
#define ZE_WINDOW_TITLE "Zelda"
#define ZE_TILE_SIZE (64)

#define ZE_MAX_ENTITIES (4096)
#define ZE_MIN_ZINDEX CLITERAL(ze::zindex_t)(0)
#define ZE_MAX_ZINDEX CLITERAL(ze::zindex_t)(10)

#define ZE_PLAYER_SPEED (200.0f)
#define ZE_PLAYER_ATTACK_SPEED (0.40f)

#endif