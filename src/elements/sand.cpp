#include "../main.hpp"
#include "directions.hpp"
#include "sand.hpp"

#include <stdint.h> 


void CSandHandler::update(uint16_t x, uint16_t y)
{

    if (Util.getGrid( DOWN ) == 0 )
    {
        GO_DOWN(x, y);
    } else if (Util.getGrid( DOWN ) == 4 || Util.getGrid( DOWN ) == 5 )
    {
        GO_DOWN(x, y);
        grid[x][y+1] = 255;
        PLACE_UP(x, y+1, 4); // water którego przesuwamy nadal się updateuje

    } else if (Util.getGrid( DOWN_RIGHT ) == 0) 
    {
        GO_DOWN_RIGHT(x, y);
    } else if (Util.getGrid( DOWN_LEFT ) == 0) 
    {
        GO_DOWN_LEFT(x, y);
    } else {
        STAY(x, y);
    }

}

