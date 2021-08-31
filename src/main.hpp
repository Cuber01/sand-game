#ifndef main_hpp
#define main_hpp

#include <inttypes.h>
#include "mouse.hpp"
#include "draw.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define rows WINDOW_WIDTH/scale
#define cols WINDOW_WIDTH/scale

extern SDL_Window* window;
extern CMouse Mouse;

extern uint8_t grid[rows][cols];

#endif