#include "../main.hpp"
#include "directions.hpp"
#include "element.hpp"

#include <stdint.h> 

#ifdef DEBUG_STACK
#include "../settings.hpp"
#endif


color_t color_list[3] =
{
    { 234, 181, 11 }, // sand 1
    { 251, 209, 72 }, // sand 2
    { 251, 242, 54 }, // sand 3
};

CElement::CElement() {}

CElement::~CElement() 
{
    #ifdef DEBUG_STACK
        stack--;
    #endif
}

void CElement::update(uint16_t x,uint16_t y) {}

void CElement::setColor( color_t color) {
    this->color = color;
}

color_t CElement::getColor() {
    return this->color;
}

void CElement::receiveHeat(float heatAmount)
{
    heatResistance -= heatAmount;
}

void CElement::emitHeat(uint16_t x, uint16_t y)
{
    if( Util.getGrid( DOWN ) )
    {
        Util.getGrid( DOWN )->receiveHeat(amountOfHeatToEmit);
    } 
    
    if ( Util.getGrid( DOWN_RIGHT ) )
    {
        Util.getGrid( DOWN_RIGHT )->receiveHeat(amountOfHeatToEmit);
    } 
    
    if ( Util.getGrid( DOWN_LEFT ) )
    {
        Util.getGrid( DOWN_LEFT )->receiveHeat(amountOfHeatToEmit);
    } 
    
    if ( Util.getGrid( UP ) )
    {
        Util.getGrid( UP )->receiveHeat(amountOfHeatToEmit);
    } 
    
    if ( Util.getGrid( UP_LEFT ) )
    {
        Util.getGrid( UP_LEFT )->receiveHeat(amountOfHeatToEmit);
    } 
    
    if ( Util.getGrid( UP_RIGHT ) )
    {
        Util.getGrid( UP_RIGHT )->receiveHeat(amountOfHeatToEmit);
    } 
    
    if ( Util.getGrid( RIGHT ) )
    {
        Util.getGrid( RIGHT )->receiveHeat(amountOfHeatToEmit);
    } 
    
    if ( Util.getGrid( LEFT ) )
    {
        Util.getGrid( LEFT )->receiveHeat(amountOfHeatToEmit);
    }
      
}

void CElement::checkHitpoints(uint16_t x, uint16_t y)
{

    if(hitpoints < 0)
    {
        grid[x][y] = 0;
        next[x][y] = 0;

        delete this;
    }

}

void CElement::checkHeat()
{
    if(heatResistance < 0 && not isBurning)
    {
        isBurning = true;
        fireStrength = 5;
    }
}



void CElement::incrementStack()
{
    #ifdef DEBUG_STACK
    stack++;
    #endif
}
