#include "../main.hpp"
#include "directions.hpp"
#include "particle.hpp"

#include <stdint.h> 
#include <cmath>
#include <algorithm>


CParticle::CParticle(color_t color, int8_t velocity_x, int8_t velocity_y)
{
    this->setColor( color );
    type = dParticleElement; 

    this->velocity_x = velocity_x;
    this->velocity_y = velocity_y; 
    incrementStack();
}

void CParticle::update(uint16_t x, uint16_t y)
{
    move(x, y);   
}

void CParticle::move(uint16_t x, uint16_t y)
{
    STAY(x, y);
}

void CParticle::fly(uint16_t x, uint16_t y, uint16_t target_x, uint16_t target_y)
{

}

void CParticle::receiveHeat(float heatAmount) {}
