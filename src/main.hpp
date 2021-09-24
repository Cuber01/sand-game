#ifndef main_hpp
#define main_hpp

#include <stdint.h>
#include "cursor.hpp"
#include "utils/util.hpp"
#include "settings.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define rows WINDOW_WIDTH/scale
#define cols WINDOW_WIDTH/scale

extern SDL_Window* window;

extern CCursor Cursor;
extern CUtil Util;

extern CElement* grid[rows][cols];
extern CElement* next[rows][cols];

#ifdef DEBUG_STACK
    extern int stack;
#endif


#endif