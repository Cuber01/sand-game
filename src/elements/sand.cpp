#include "../main.hpp"
#include "directions.hpp"
#include "sand.hpp"


#include <stdint.h> 


void CSandHandler::sandUpdate(uint16_t x, uint16_t y)
{

    if (Util.getGrid( DOWN ) == 0 ) // down
    {
        GO_DOWN(x, y);
    } else if (Util.getGrid( DOWN_RIGHT ) == 0) // down right
    {
        GO_DOWN_RIGHT(x, y);
    } else if (Util.getGrid( DOWN_LEFT ) == 0) // down left
    {
        GO_DOWN_LEFT(x, y);
    } else {
        STAY(x, y);
    }

}
