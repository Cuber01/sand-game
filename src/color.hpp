#ifndef color_hpp
#define color_hpp

#include <stdint.h>

typedef struct color_t
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

extern color_t color_list[4];

//color_t doad = (color_t){ .r = 0, .g = 1, .b = 2  };

#endif