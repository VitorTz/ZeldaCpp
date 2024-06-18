#include "globals.h"


Font ze::globals::gFont;


void ze::globals::init() {
    ze::globals::gFont = LoadFontEx(TH_FONT_PATH, 52, 0, 255);
}


void ze::globals::close() {
    UnloadFont(ze::globals::gFont);
}


Font ze::globals::get_font() {
    return ze::globals::gFont;
}