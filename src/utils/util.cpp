#include "../main.hpp" 
#include "util.hpp"

#include "../elements/element.hpp"

#include <stdint.h>
#include <random>

// void CUtil()
// {
//     std::default_random_engine generator;
// }

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

uint8_t CUtil::random(uint16_t min, uint8_t max)
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
    static std::default_random_engine generator; // TODO
    std::bernoulli_distribution distribution(chance);

    return distribution(generator);

}
