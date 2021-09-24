#include "../main.hpp"
#include "directions.hpp"
#include "smoke.hpp"

#include <stdint.h> 


color_t smoke_color = { 60, 67, 73 };

CSmoke::CSmoke()
{
    this->setColor( smoke_color );
    type = dSmokeElement;
    lifetime = Util.random_u16(200,400); // check/adjust numbers TODO
}

void CSmoke::update(uint16_t x, uint16_t y)
{
    handleLifetime(x, y);

    move(x, y);
    
}

void CSmoke::move(uint16_t x, uint16_t y)
{

    if (Util.getGrid( UP ) == 0 && Util.getNext( UP ) == 0 && Util.random(1, 2) == 1) 
    {

        GO_UP(x, y);

    } else if (Util.getGrid( UP_RIGHT ) == 0 && Util.getNext( UP_RIGHT ) == 0 && Util.randomBool() == true) 
    {

        GO_UP_RIGHT(x, y);

    } else if (Util.getGrid( UP_LEFT ) == 0 && Util.getNext( UP_LEFT ) == 0 && Util.randomBool() == true) 
    {

        GO_UP_LEFT(x, y);

    } else if (Util.getGrid( RIGHT ) == 0 && Util.getGrid( LEFT ) == 0 && Util.getNext( RIGHT ) == 0 && Util.getNext( LEFT ) == 0 && Util.randomBool() == true)
    {

        if(Util.randomBool() == true)
        {
            GO_RIGHT(x, y);
        } else {
            GO_LEFT(x, y);
        }

    } else if (Util.getGrid( RIGHT ) == 0 && Util.getNext( RIGHT ) == 0 && Util.randomBool() == true)  
    {

        GO_RIGHT(x, y);

    } else if (Util.getGrid( LEFT ) == 0 && Util.getNext( LEFT ) == 0 && Util.randomBool() == true)
    {

        GO_LEFT(x, y);

    } else { 

        STAY(x, y);    

    }


}

void CSmoke::handleLifetime(uint16_t x, uint16_t y)
{
    lifetime--;

    if(lifetime < 0)
    {
        // goodbye cruel world TODO?
        grid[x][y] = 0;
        delete this;
    }
}

void CSmoke::receiveHeat(float heatAmount) {}

