#include "main.hpp"
#include "sand.hpp"

#include <stdint.h> 

void CSandHandler::sandUpdate(uint16_t x, uint16_t y)
{

    if (Util.getGrid( x, y+1 ) == 0 ) // down
    {
        next[x][y+1] = 1;
    } else if (Util.getGrid( x+1, y+1) == 0) // down right
    {
        next[x+1][y+1] = 1;
    } else if (Util.getGrid( x-1, y+1) == 0) // down left
    {
        next[x-1][y+1] = 1;
    } else {
        next[x][y] = 1;
    }

}
