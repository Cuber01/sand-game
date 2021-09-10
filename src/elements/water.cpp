#include "../main.hpp"
#include "directions.hpp"
#include "../utils/util.hpp"
#include "water.hpp"


#include <stdint.h> 



CWater::CWater()
{
    this->setColor({ 71, 126, 255 });
    this->movesRight = Util.random(0, 1);
}

void CWater::move(uint16_t x, uint16_t y)
{

    if (Util.getGrid( DOWN ) == 0 && Util.getNext( DOWN ) == 0) 
    {
        GO_DOWN(x, y);
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

// 1 = right
// -1 = left
void CWater::spread(uint16_t x, uint16_t y, int8_t right)
{
    for(uint8_t i = 1; i <= dispersionRate; i++)
    {
        if(Util.getGrid(x+(i*right), y) == 0 && Util.getNext(x+(i*right), y) == 0)
        {
            if(Util.getGrid(x + ((i+1)*right) , y) != 0 && Util.getNext(x + ((i+1)*right) , y) != 0)
            {
                GO(x, y, x+(i*right), y);
                return;
            }

        }    
    }

    GO(x, y, x+(dispersionRate*right), y);

    

}

void CWater::update(uint16_t x, uint16_t y)
{
    move(x, y);
}

