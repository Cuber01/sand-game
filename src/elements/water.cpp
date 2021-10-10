#include "../main.hpp"
#include "directions.hpp"
#include "../utils/util.hpp"
#include "derived/steam.hpp"
#include "water.hpp"

#include <stdint.h> 
#include <cmath>



CWater::CWater()
{
    this->setColor({ 71, 126, 255 });
    heatResistance = 3;
    this->movesRight = Util.random(0, 1);
    type = dWaterElement;
    incrementStack();
}


void CWater::move(uint16_t x, uint16_t y)
{


    if(!willBeReplaced)
    {
        if (Util.getGrid( DOWN ) == 0 && Util.getNext( DOWN ) == 0) 
        {
            fall(x, y);
        } else if (Util.getGrid( DOWN_RIGHT ) == 0 && Util.getNext( DOWN_RIGHT ) == 0) 
        {
            //spread(x, y+1, true);
            GO_DOWN_RIGHT(x, y);
        } else if (Util.getGrid( DOWN_LEFT ) == 0 && Util.getNext( DOWN_LEFT ) == 0) 
        {
            //spread(x, y+1, false);
            GO_DOWN_LEFT(x, y);
        } else if (Util.getGrid( RIGHT ) == 0 && Util.getGrid( LEFT ) == 0 && Util.getNext( RIGHT ) == 0 && Util.getNext( LEFT ) == 0)
        {
            if(movesRight)
            {
                spread(x, y, 1);
            } else {
                spread(x, y, -1);
            }
        } else if (Util.getGrid( RIGHT ) == 0 && Util.getNext( RIGHT ) == 0)  
        {
            movesRight = true;
            spread(x, y, 1);
        } else if (Util.getGrid( LEFT ) == 0 && Util.getNext( LEFT ) == 0)
        {
            movesRight = false;
            spread(x, y, -1);
        } else { 
            STAY(x, y);
        }
    }

    checkHeat();

}

// 1 = right
// -1 = left
void CWater::spread(uint16_t x, uint16_t y, int8_t direction)
{
    for(uint8_t i = 1; i <= dispersionRate; i++)
    {
        if(Util.getGrid(x+(i*direction), y) == 0 && Util.getNext(x+(i*direction), y) == 0)
        {
            if(Util.getGrid(x + ((i+1)*direction) , y) != 0 && Util.getNext(x + ((i+1)*direction) , y) != 0)
            {
                GO(x, y, x+(i*direction), y);
                return;
            }

        } else {
            STAY(x, y);
            return;
        }   
    }

    GO(x, y, x+(dispersionRate*direction), y);

    

}

void CWater::fall(uint16_t x, uint16_t y)
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

    if(velocity_y < MAX_FALL_SPEED)
    {
        velocity_y += GRAVITY;
    } else {
        velocity_y = MAX_FALL_SPEED;
    }

}

void CWater::update(uint16_t x, uint16_t y)
{
    if(isBurning)
    {
        grid[x][y] = 0;
        next[x][y] = new CSteam();
        delete this;
    }


    move(x, y);
}

