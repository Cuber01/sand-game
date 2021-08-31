#ifndef main_hpp
#define main_hpp

#include <stdint.h>
#include "cursor.hpp"
#include "util.hpp"
#include "render.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define rows WINDOW_WIDTH/scale
#define cols WINDOW_WIDTH/scale

extern SDL_Window* window;

extern CCursor Cursor;
extern CUtil Util;

extern uint8_t grid[rows][cols];
extern uint8_t next[rows][cols];

#endif