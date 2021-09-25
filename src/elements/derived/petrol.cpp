#include "../../main.hpp"
#include "../water.hpp"
#include "fire.hpp"
#include "petrol.hpp"

// seed

color_t petrol_color = { 28, 37, 48 };


CPetrol::CPetrol()
{
    this->setColor( petrol_color );
    type = dPetrolElement;
    hitpoints = 2;
    amountOfHeatToEmit = 5;
}

void CPetrol::update(uint16_t x, uint16_t y)
{
    if(isBurning)
    {
        emitHeat(x, y);
        hitpoints--;
        setColor(fire_color_list2[Util.random(0, 2)]);

        checkHitpoints(x, y);

    }

    move(x, y);

    checkHeat();
}

void CPetrol::checkHitpoints(uint16_t x, uint16_t y)
{
    if(hitpoints < 0)
    {
        grid[x][y] = 0;

        if(Util.randomBool())
        {
            next[x][y] = new CFire();
        } else {
            next[x][y] = 0;
        }

        delete this;
    }
}

