#include "main.hpp" 
#include "util.hpp"

#include <stdint.h>


uint8_t CUtil::getGrid(uint16_t x, uint16_t y)
{
    uint8_t rv = grid[x][y];
    return rv;

}