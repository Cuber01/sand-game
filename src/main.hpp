#ifndef main_hpp
#define main_hpp

#include <stdint.h>
#include "cursor.hpp"
#include "utils/util.hpp"
#include "settings.hpp"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

#define ROWS WINDOW_WIDTH/SCALE
#define COLS WINDOW_WIDTH/SCALE

extern SDL_Window* window;

extern CCursor Cursor;
extern CUtil Util;

extern CElement* grid[ROWS][COLS];
extern CElement* next[ROWS][COLS];

#ifdef DEBUG_STACK
    extern int stack;
#endif


#endif