
// slow mode
//#define SLOW

// counts and prints the amount of all currently running elements
// #define DEBUG_STACK

// use software rendering
// #define SOFTWARE_RENDERING

// size of the square drawn per cell (SCALE 4 = each cell is a 4x4 square)
#define SCALE 4

// gravity factor
#define GRAVITY 0.2

// max number of cells we can travel per frame while falling
#define MAX_FALL_SPEED 5

// friction value of bounds [currently used as a default friction everywhere]
#define BOUNDS_FRICTION 0.1

// whether we want a gui or not
// #define OPENGL_GUI

// whether we want map loader to work or not
// #define MAP_LOADER

// whether we compile for web or not. If we do, OPENGL_GUI has to be undefined.
// #define __EMSCRIPTEN

