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
    // if (!isFalling)
    // {
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
            isFalling = false;
        }
    // } else {
    //     if (Util.getGrid( DOWN ) == 0)
    //     {
    //         fall(x, y);
    //         isFalling = true;
    //     }
    // }
}

void CSand::update(uint16_t x, uint16_t y)
{
    move(x, y);
    //nudge_neighbors(x, y);
    
}

void CSand::nudge_neighbors(uint16_t x, uint16_t y)
{
    if(Util.getGrid( RIGHT )->type == dSandElement)
    {
        Util.getGrid( RIGHT )->isFalling = true;
    } else if (Util.getGrid( LEFT )->type == dSandElement)
    {
        Util.getGrid( RIGHT )->isFalling = true;
    } 
}

void CSand::fall(uint16_t x, uint16_t y)
{
    int8_t rounded_vel_y = std::roundf(velocity_y);


    for(int8_t i = 1; i <= rounded_vel_y; i++)
    {
        if(Util.getGrid(x, y+i) == 0) // TODO if i add getnext checks it doesnt work
        {
            if(Util.getGrid(x , y + i+1) != 0)
            {
                GO(x, y, x, y+i);
                return;
            }
        
        } else {
            STAY(x, y);
            return;
        }   
    }

    GO(x, y, x, y+rounded_vel_y);

    if(velocity_y < max_fall_speed)
    {
        velocity_y += gravity;
    } else {
        velocity_y = max_fall_speed;
    }

}

