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
    //     if (x == target_x && y == target_y) 
    //     {
    //         STAY(x, y);
    //         return;
    //     }

    //     uint16_t xDiff = x - target_x;
    //     uint16_t yDiff = y - target_y;

    //     bool xDiffIsLarger = abs(xDiff) > abs(yDiff);
        
    //     int8_t xModifier = xDiff < 0 ? 1 : -1;
    //     int8_t yModifier = yDiff < 0 ? 1 : -1;

    //     int longerSideLength = std::max(abs(xDiff), abs(yDiff));
    //     int shorterSideLength = std::min(abs(xDiff), abs(yDiff));


    //     float slope = (shorterSideLength == 0 || longerSideLength == 0) ? 0 : ((float) (shorterSideLength) / (longerSideLength));
    //     int shorterSideIncrease;
    //         for (int i = 1; i <= longerSideLength; i++) {
                
    //             shorterSideIncrease = round(i * slope);
                
    //             int yIncrease, xIncrease;

    //             if (xDiffIsLarger) {
    //                 xIncrease = i;
    //                 yIncrease = shorterSideIncrease;
    //             } else {
    //                 yIncrease = i;
    //                 xIncrease = shorterSideIncrease;
    //             }

    //             int currentY = matrixY1 + (yIncrease * yModifier);
    //             int currentX = matrixX1 + (xIncrease * xModifier);

    //             if (!Util.isOutOfBounds(currentX, currentY)) {
    //                 function.invoke();
    //             }
    //      }
    //  }
}

void CParticle::receiveHeat(float heatAmount) {}
