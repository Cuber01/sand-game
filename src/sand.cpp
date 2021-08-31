#include "main.hpp"


void sandUpdate(uint16_t x, uint16_t y)
{

    if (getGrid( x, y+1 ) == 0 ) // down
    {
        grid[x][y+1] = 1;
    } else if (getGrid( x+1, y+1) == 0) // down right
    {
        grid[x+1][y+1] = 1;
    } else if (getGrid( x-1, y+1) == 0) // down left
    {
        grid[x-1][y+1] = 1;
    } 

}
