#include "../main.hpp" 
#include "util.hpp"

#include "../elements/element.hpp"
#include <stdint.h>



bool CUtil::isOutOfBounds(uint16_t x, uint16_t y)
{
    if(x >= rows || x <= 0 || y >= cols || y <= 0) {
        return true;
    }

    return false;
}

CElement* CUtil::getNext(uint16_t x, uint16_t y)
{
    if(isOutOfBounds(x, y))
    {
        return &bounds; 
    }

    return next[x][y];

}

CElement* CUtil::getGrid(uint16_t x, uint16_t y)
{
    if(isOutOfBounds(x, y))
    {
        return &bounds;
    }

    return grid[x][y];

}

uint8_t CUtil::random(uint16_t min, uint8_t max)
{
    return rand()%(max-min + 1) + min;
}

