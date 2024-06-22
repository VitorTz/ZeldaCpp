#pragma once
#include "types.h"


#define ZE_SCREEN_WIDTH (1280)
#define ZE_SCREEN_HEIGHT (720)
#define ZE_WINDOW_TITLE "Zelda"
#define ZE_FIRST_SCENE CLITERAL(ze::SceneId){ze::TitleScreenId}

#define ZE_MAX_ENTITIES (4096)
#define ZE_DEBUD_MODE (false)

#define ZE_TILE_SIZE (64)

#define ZE_MIN_ZINDEX CLITERAL(ze::z_index)(0)
#define ZE_MAX_ZINDEX CLITERAL(ze::z_index)(10)

#define ZE_PLAYER_SPEED (150.0f);
#define ZE_PLAYER_X_POS (2000.0f)
#define ZE_PLAYER_Y_POS (1430.0f)

