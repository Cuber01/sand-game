#include "../main.hpp"
#include "directions.hpp"
#include "water.hpp"

#include <stdint.h> 



CWater::CWater()
{
    color = my_color;
}

void CWater::setColor()
{
    color = my_color;
}

void CWater::move(uint16_t x, uint16_t y)
{

    if (Util.getGrid( DOWN ) == 0 && Util.getNext( DOWN ) == 0) 
    {
        GO_DOWN(x, y);
    } else if (Util.getGrid( DOWN_RIGHT ) == 0 && Util.getNext( DOWN_RIGHT ) == 0) 
    {
        GO_DOWN_RIGHT(x, y);
    } else if (Util.getGrid( DOWN_LEFT ) == 0 && Util.getNext( DOWN_LEFT ) == 0) 
    {
        GO_DOWN_LEFT(x, y);
    } else if (Util.getGrid( RIGHT ) == 0 && Util.getGrid( LEFT ) == 0 && Util.getNext( RIGHT ) == 0 && Util.getNext( LEFT ) == 0)
    {
        if(movesRight)
        {
            GO_RIGHT(x, y);
        } else {
            GO_LEFT(x, y);
        }
    } else if (Util.getGrid( RIGHT ) == 0 && Util.getNext( RIGHT ) == 0)  
    {
        movesRight = true;
        GO_RIGHT(x, y);
    } else if (Util.getGrid( LEFT ) == 0 && Util.getNext( LEFT ) == 0)
    {
        movesRight = false;
        GO_LEFT(x, y);
    } else { 
        STAY(x, y);
    }

}

void CWater::update(uint16_t x, uint16_t y)
{
    move(x, y);
}

