#ifndef color_hpp
#define color_hpp

#include <stdint.h>

#define KEY_SAND_MODE_NUMKEY1  49
#define KEY_WATER_MODE_NUMKEY2 50
#define KEY_WOOD_MODE_NUMKEY3  51
#define KEY_FIRE_MODE_NUMKEY4  52
#define KEY_SMOKE_MODE_NUMKEY5 53

// real keys:    1  2  3  4  5  6  7  8  9  0
// key numbers: 49 50 51 52 53 54 55 56 57 48

typedef enum {
    dNoneElement =0,
    dSandElement,
    dDirtElement,
    dFireElement,
    dWaterElement,
    dSmokeElement,
    dSteamElement,
    dWoodElement
} element_t;


typedef struct color_t
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

extern color_t fire_color_list2[3];

// color_t color_list[]
// {
//     { 0, 0, 0      },      // air  0
//     { 234, 181, 11 }, // sand 1
//     { 251, 209, 72 }, // sand 2
//     { 251, 242, 54 }, // sand 3
//     { 71, 126, 255 }, // water moving right 4
//     { 71, 126, 255 }, // water moving left  5  
//     { 75, 27, 5    }, // wood 6
//     { 60, 67, 73   }, // smoke 7     
//     { 255, 160, 1  }, // fire 8
//     { 255, 107, 1  }, // fire 9
//     { 255, 79, 1   }, // fire 10
// };

//color_t doad = (color_t){ .r = 0, .g = 1, .b = 2  };

#endif