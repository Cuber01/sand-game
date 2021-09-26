#include "../../main.hpp"
#include "../directions.hpp"
#include "cracked_brick.hpp"

#include "../../utils/util.hpp"

#define sRETURN { isFalling = true; return; }

color_t cracked_brick_color_list[3] =
{
    { 76, 73, 81 },
    { 40, 38, 48 }, 
    { 26, 26, 36 },
};

CCrackedBrick::CCrackedBrick()
{
    this->setColor( cracked_brick_color_list[Util.random(0, 2)] );
    canBeNudged = true;
    type = dCrackedBrickElement;
    isFalling = false;
    nudgeChance = 0.001;
}

void CCrackedBrick::notFallingUpdate(uint16_t x, uint16_t y) 
{
    STAY(x, y);
    velocity_y = 0;
}

void CCrackedBrick::receiveHeat(float heatAmount) {}