#include "../main.hpp"
#include "directions.hpp"
#include "sand.hpp"

#include "../utils/util.hpp"
#include <float.h>
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
        fall(x, y);
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
        velocity_y = 0;
    }
}

void CSand::update(uint16_t x, uint16_t y)
{
    move(x, y);
}

void CSand::fall(uint16_t x, uint16_t y)
{
    int8_t vel_y = std::roundf(velocity_y);
    printf("%d", vel_y);

    
    GO_DOWN( x, y + vel_y );

    if(velocity_y < max_fall_speed)
    {
        velocity_y += gravity;
    }

    hasBeenUpdated = true;
}

