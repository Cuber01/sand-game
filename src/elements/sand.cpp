#include "../main.hpp"
#include "directions.hpp"
#include "sand.hpp"

#include "../utils/util.hpp"
#include <stdint.h> 

color_t color_list[3] =
{
    { 234, 181, 11 }, // sand 1
    { 251, 209, 72 }, // sand 2
    { 251, 242, 54 }, // sand 3
};

CSand::CSand()
{
    color = color_list[Util.random(0, 2)]; // TODO
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

