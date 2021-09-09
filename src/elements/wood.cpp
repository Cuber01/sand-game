#include "../main.hpp"
#include "directions.hpp"
#include "wood.hpp"

#include <stdint.h> 

CWood::CWood()
{
    this->setColor( wood_color );    
}

void CWood::stay(uint16_t x, uint16_t y)
{
    STAY(x, y);
}

void CWood::update(uint16_t x, uint16_t y)
{
    stay(x, y);
}

