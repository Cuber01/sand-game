#include "../main.hpp"
#include "directions.hpp"
#include "smoke.hpp"
#include "../utils/data.hpp"
#include "wall.hpp"

#include <stdint.h> 

CWall::CWall()
{
    this->setColor( wall_color );  
    type = dWallElement;
}

void CWall::stay(uint16_t x, uint16_t y)
{
    STAY(x, y);
}

void CWall::receiveHeat(float heatAmount) {}

void CWall::update(uint16_t x, uint16_t y)
{
    stay(x, y);  
}

