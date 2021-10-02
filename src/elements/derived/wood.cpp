#include "../../main.hpp"
#include "../directions.hpp"
#include "../smoke.hpp"
#include "../../utils/data.hpp"
#include "wood.hpp"

#include <stdint.h> 

CWood::CWood()
{
    this->setColor( wood_color );  
    initialHeatResistance = 10;
    heatResistance = 3;  
    type = dWoodElement;
    incrementStack();
}

void CWood::checkHitpoints(uint16_t x, uint16_t y)
{

    if(hitpoints < 0)
    {
        grid[x][y] = 0;

        if(Util.randomBool())
        {
            next[x][y] = 0;
        } else {
            next[x][y] = new CSmoke();
        }

        delete this;
    }

}

void CWood::receiveHeat(float heatAmount)
{
    heatResistance -= heatAmount;
}

void CWood::update(uint16_t x, uint16_t y)
{
    if(isBurning)
    {
        emitHeat(x, y);   
        this->setColor( fire_color_list2[Util.random(0,2)] );    
        hitpoints = hitpoints - 0.4;

        if(Util.isSurrounded(x, y))
        {
            fireStrength--;

            if(fireStrength < 0)
            {
                this->setColor( wood_color );
                heatResistance = initialHeatResistance;  
                isBurning = false;
            }
        } else {
            if(Util.getGrid( UP ) == 0) {

            }
        }
    }

    stay(x, y);

    checkHeat();
    checkHitpoints(x, y);
    
}

