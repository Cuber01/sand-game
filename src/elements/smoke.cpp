#include "../main.hpp"
#include "directions.hpp"
#include "smoke.hpp"

#include <stdint.h> 


void CSmokeHandler::update(uint16_t x, uint16_t y)
{

 if (Util.getGrid( UP ) == 0 && Util.getNext( UP ) == 0 && floor(rand()%2) == 1) 
    {
        GO_UP(x, y, 6);
    } else if (Util.getGrid( UP_RIGHT ) == 0 && Util.getNext( UP_RIGHT ) == 0 && floor(rand()%2) == 1) 
    {
        GO_UP_RIGHT(x, y, 6);
    } else if (Util.getGrid( UP_LEFT ) == 0 && Util.getNext( UP_LEFT ) == 0 && floor(rand()%2) == 1) 
    {
        GO_UP_LEFT(x, y, 6);
    } else if (Util.getGrid( RIGHT ) == 0 && Util.getGrid( LEFT ) == 0 && Util.getNext( RIGHT ) == 0 && Util.getNext( LEFT ) == 0 && floor(rand()%2) == 1)
    {
        
        if(floor(rand()%2) == 1)
        {
            GO_RIGHT(x, y, 6);
        } else {
            GO_LEFT(x, y, 6);
        }

    } else if (Util.getGrid( RIGHT ) == 0 && Util.getNext( RIGHT ) == 0 && floor(rand()%2) == 1)  
    {
        GO_RIGHT(x, y, 6);
    } else if (Util.getGrid( LEFT ) == 0 && Util.getNext( LEFT ) == 0 && floor(rand()%2) == 1)
    {
        GO_LEFT(x, y, 6);
    } else { 
        STAY(x, y, Util.getGrid( ME ));
    }


}

