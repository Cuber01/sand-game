#include "../main.hpp"
#include "directions.hpp"
#include "fire.hpp"

#include <stdint.h> 


void CFireHandler::update(uint16_t x, uint16_t y)
{

    handleMovement(x, y);
    handleIgnite(x, y);


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


void CFireHandler::handleIgnite(uint16_t x, uint16_t y)
{

    if (Util.getGrid( UP ) == 6 && Util.getNext( UP ) == 6 && Util.random(1, spread_chance) == 1) 
    {
        PLACE_UP(x, y, new_fire_lifetime);
    }

    if (Util.getGrid( UP_RIGHT ) == 6 && Util.getNext( UP_RIGHT ) == 6 && Util.random(1, spread_chance) == 1) 
    {
        PLACE_UP_RIGHT(x, y, new_fire_lifetime);
    }
    
    if (Util.getGrid( UP_LEFT ) == 6 && Util.getNext( UP_LEFT ) == 6 && Util.random(1, spread_chance) == 1) 
    {
        PLACE_UP_LEFT(x, y, new_fire_lifetime);
    }
    
    if (Util.getGrid( RIGHT ) == 6 && Util.getNext( RIGHT ) == 6 && Util.random(1, spread_chance) == 1)  
    {
        PLACE_RIGHT(x, y, new_fire_lifetime);
    }
    
    if (Util.getGrid( LEFT ) == 6 && Util.getNext( LEFT ) == 6 && Util.random(1, 100) == 1)
    {
        PLACE_LEFT(x, y, new_fire_lifetime);
    }

    if (Util.getGrid( DOWN_LEFT ) == 6 && Util.getNext( DOWN_LEFT ) == 6 && Util.random(1, spread_chance) == 1) 
    {
        PLACE_DOWN_LEFT(x, y, new_fire_lifetime);
    }

    if (Util.getGrid( DOWN_RIGHT ) == 6 && Util.getNext( DOWN_RIGHT ) == 6 && Util.random(1, spread_chance) == 1) 
    {
        PLACE_DOWN_RIGHT(x, y, new_fire_lifetime);
    }

    if (Util.getGrid( DOWN ) == 6 && Util.getNext( DOWN ) == 6 && Util.random(1, spread_chance) == 1) 
    {
        PLACE_DOWN(x, y, new_fire_lifetime);
    }

}

