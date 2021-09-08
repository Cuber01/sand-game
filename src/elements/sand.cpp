#include "../main.hpp"
#include "directions.hpp"
#include "sand.hpp"

#include <stdint.h> 

#define DEFAUL_COLOR { 234, 181, 11 }

CSand::CSand()
{
    color = DEFAUL_COLOR;
}

void CSand::move(uint16_t x, uint16_t y)
{
    if (Util.getGrid( DOWN ) == 0)
    {
        GO_DOWN(x, y);
    } else if (Util.getGrid( DOWN_RIGHT ) == 0) 
    {
        GO_DOWN_RIGHT(x, y);
    } else if (Util.getGrid( DOWN_LEFT ) == 0) 
    {
        GO_DOWN_LEFT(x, y);
    } else {
        STAY(x, y);
    }
}

void CSand::update(uint16_t x, uint16_t y)
{
    move(x, y);
}

