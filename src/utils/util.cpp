#include "../main.hpp" 
#include "util.hpp"

#include "../elements/element.hpp"
#include "../elements/directions.hpp"

#include <stdint.h>
#include <random>


bool CUtil::isOutOfBounds(uint16_t x, uint16_t y)
{
    if(x >= rows || x <= 0 || y >= cols || y <= 0) {
        return true;
    }

    return false;
}

CElement* CUtil::getNext(uint16_t x, uint16_t y)
{
    if(isOutOfBounds(x, y))
    {
        return &bounds; 
    }

    return next[x][y];

}

CElement* CUtil::getGrid(uint16_t x, uint16_t y)
{
    if(isOutOfBounds(x, y))
    {
        return &bounds;
    }

    return grid[x][y];

}

bool CUtil::amISurrounded(uint16_t x, uint16_t y)
{
    if(
        getGrid( DOWN ) && getGrid( UP )
        && getGrid( LEFT ) && getGrid( RIGHT )
        && getGrid( DOWN_LEFT ) && getGrid( DOWN_RIGHT )
        && getGrid( UP_LEFT ) && getGrid( UP_RIGHT ) 
    ) 
    {
        return true;
    }

    return false;
}

uint8_t CUtil::random(uint8_t min, uint8_t max)
{
    return rand()%(max-min + 1) + min;
}

uint16_t CUtil::random_u16(uint16_t min, uint16_t max)
{
    return rand()%(max-min + 1) + min;
}


int8_t CUtil::randomPositiveNegative()
{
    uint8_t choice = randomBool();

    if(choice == 0) {
        return 1; 
    } else {
        return -1;
    } 
}


bool CUtil::randomBool()
{
    return rand() & 1;
}


bool CUtil::randomBoolChance(float chance)
{   
    static std::default_random_engine generator;

    std::bernoulli_distribution distribution(chance);

    return distribution(generator);

}

