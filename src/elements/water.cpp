#include "../main.hpp"
#include "directions.hpp"
#include "water.hpp"

#include <stdint.h> 


void CWaterHandler::waterUpdate(uint16_t x, uint16_t y)
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
        if(Util.getGrid( ME ) == 4)
        {
            GO_RIGHT(x, y, 4);
        } else {
            GO_LEFT(x, y, 5);
        }

    } else if (Util.getGrid( RIGHT ) == 0 && Util.getNext( RIGHT ) == 0)  
    {
        GO_RIGHT(x, y, 4);
    } else if (Util.getGrid( LEFT ) == 0 && Util.getNext( LEFT ) == 0)
    {
        GO_LEFT(x, y, 5);
    } else { 
        STAY(x, y);
    }

}
