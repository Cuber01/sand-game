#include "../main.hpp"
#include "directions.hpp"
#include "sand.hpp"

#include "../utils/util.hpp"
#include <stdint.h> 

color_t sand_color_list[3] =
{
    { 234, 181, 11 },
    { 251, 209, 72 }, 
    { 251, 242, 54 }, 
};

CSand::CSand()
{
    this->setColor( sand_color_list[Util.random(0, 2)] );
    type = dSandElement;
}

void CSand::move(uint16_t x, uint16_t y)
{
    if (Util.getGrid( DOWN ) == 0)
    {
        GO_DOWN(x, y);
    } else if (Util.getGrid( DOWN )->type == dWaterElement)
    {
        GO_DOWN(x, y); // TODO 
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

