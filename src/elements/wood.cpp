#include "../main.hpp"
#include "directions.hpp"
#include "../utils/data.hpp"
#include "wood.hpp"

#include <stdint.h> 

CWood::CWood()
{
    this->setColor( wood_color );  
    initialHeatResistance = 3;
    heatResistance = 3;  
    type = dWoodElement;
}

void CWood::stay(uint16_t x, uint16_t y)
{
    STAY(x, y);
}

void CWood::update(uint16_t x, uint16_t y)
{
    if(isBurning)
    {
        emitHeat(x, y);   
        this->setColor( fire_color_list2[Util.random(0,2)] );    
        
        if(Util.amISurrounded(x, y))
        {
            this->setColor( wood_color );
            heatResistance = 10;  
            isBurning = false;
        }
    }

    stay(x, y);
    checkHeat();
}

