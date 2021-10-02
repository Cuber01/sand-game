#ifndef main_hpp
#define main_hpp

#include <stdint.h>
#include "cursor.hpp"
#include "utils/util.hpp"
#include "utils/data.hpp"
#include "settings.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define ROWS WINDOW_WIDTH/SCALE
#define COLS WINDOW_WIDTH/SCALE

extern SDL_Window* window;

extern CCursor Cursor;
extern CUtil Util;

extern CElement* grid[ROWS][COLS];
extern CElement* next[ROWS][COLS];
extern element_t elementSlots[10];

#ifdef DEBUG_STACK
    extern int stack;
#endif


#endif