#ifndef color_hpp
#define color_hpp

#include <inttypes.h>

typedef struct color_t
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

extern color_t color_list[6]
{
    { 0, 0, 0 },      // air
    { 219, 211, 35 }, // sand 1
    { 233, 181, 11 }, // sand 2
    { 251, 209, 72 }, // sand 3
    { 251, 242, 54 }, // sand 4
    { 215, 207, 21 }  // sand 5               
};

//color_t doad = (color_t){ .r = 0, .g = 1, .b = 2  };

#endif