#ifndef color_hpp
#define color_hpp

#include <stdint.h>

#define SAND_MODE  49
#define WATER_MODE 50
#define WOOD_MODE  51
#define FIRE_MODE  52
#define SMOKE_MODE 53

// real keys:    1  2  3  4  5  6  7  8  9  0
// key numbers: 49 50 51 52 53 54 55 56 57 48



typedef struct color_t
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

extern color_t color_list[];

//color_t doad = (color_t){ .r = 0, .g = 1, .b = 2  };

#endif