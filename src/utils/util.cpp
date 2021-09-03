#include "../main.hpp" 
#include "util.hpp"

#include <stdint.h>

bool CUtil::outOfBounds(uint16_t x, uint16_t y)
{
    if(x >= rows || x <= 0 || y >= cols || y <= 0) {
        return true;
    }

    return false;
}

uint8_t CUtil::getNext(uint16_t x, uint16_t y)
{
    if(outOfBounds(x, y))
    {
        return 255;
    }

    return next[x][y];

}

uint8_t CUtil::getGrid(uint16_t x, uint16_t y)
{
    if(outOfBounds(x, y))
    {
        return 255;
    }

    return grid[x][y];

}

uint8_t CUtil::random(uint16_t min, uint8_t max)
{
    return rand()%(max-min + 1) + min;
}

