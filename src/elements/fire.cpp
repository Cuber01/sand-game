#include "../main.hpp"
#include "directions.hpp"
#include "fire.hpp"

#include <stdint.h> 


void CFireHandler::update(uint16_t x, uint16_t y)
{

    handleMovement(x, y);


}

void CFireHandler::handleMovement(uint16_t x, uint16_t y)
{
    
    uint8_t me_decremented = Util.getGrid( ME ) - 1;

    if (Util.getGrid( UP ) == 0 && Util.getNext( UP ) == 0 && Util.random(1, 2) == 1) 
    {
        PLACE_UP(x, y, me_decremented);
    } else if (Util.getGrid( UP_RIGHT ) == 0 && Util.getNext( UP_RIGHT ) == 0 && Util.random(1, 2) == 1) 
    {
        PLACE_UP_RIGHT(x, y, me_decremented);
    } else if (Util.getGrid( UP_LEFT ) == 0 && Util.getNext( UP_LEFT ) == 0 && Util.random(1, 2) == 1) 
    {
        PLACE_UP_LEFT(x, y, me_decremented);
    } else if (Util.getGrid( RIGHT ) == 0 && Util.getGrid( LEFT ) == 0 && Util.getNext( RIGHT ) == 0 && Util.getNext( LEFT ) == 0 && Util.random(1, 2) == 1)
    {
        
        if(Util.random(1, 2) == 1)
        {
            PLACE_RIGHT(x, y, me_decremented);
        } else {
            PLACE_LEFT(x, y, me_decremented);
        }

    } else if (Util.getGrid( RIGHT ) == 0 && Util.getNext( RIGHT ) == 0 && Util.random(1, 2) == 1)  
    {
        PLACE_RIGHT(x, y, me_decremented);
    } else if (Util.getGrid( LEFT ) == 0 && Util.getNext( LEFT ) == 0 && Util.random(1, 2) == 1)
    {
        PLACE_LEFT(x, y, me_decremented);
    } else { 
        PLACE_ON_ME(x, y, me_decremented);
    }

}

// void CFireHandler::handleIgnite(uint16_t x, uint16_t y)
// {
//     if (Util.getGrid( UP ) == 0 && Util.getNext( UP ) == 0) 
//     {
//         GO_UP(x, y, 200);
//     }

//     if (Util.getGrid( UP_RIGHT ) == 0 && Util.getNext( UP_RIGHT ) == 0) 
//     {
//         GO_UP_RIGHT(x, y, 200);
//     }
    
//     if (Util.getGrid( UP_LEFT ) == 0 && Util.getNext( UP_LEFT ) == 0) 
//     {
//         GO_UP_LEFT(x, y, 200);
//     }
    
//     if (Util.getGrid( RIGHT ) == 0 && Util.getNext( RIGHT ) == 0 && Util.random(1, 2) == 1)  
//     {
//         GO_RIGHT(x, y, 200);
//     }
    
//     if (Util.getGrid( LEFT ) == 0 && Util.getNext( LEFT ) == 0 && Util.random(1, 2) == 1)
//     {
//         GO_LEFT(x, y, 200);
//     }

//     if (Util.getGrid( DOWN_LEFT ) == 0 && Util.getNext( DOWN_LEFT ) == 0) 
//     {
//         GO_DOWN_LEFT(x, y, 200);
//     }

// }

