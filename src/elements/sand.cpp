#include "../main.hpp"
#include "directions.hpp"
#include "sand.hpp"

#include <stdint.h> 


void CSandHandler::sandUpdate(uint16_t x, uint16_t y)
{

    if (Util.getGrid( DOWN ) == 0 )
    {
        GO_DOWN(x, y);
    } else if (Util.getGrid( DOWN ) == 4 || Util.getGrid( DOWN ) == 5 )
    {
        GO_DOWN(x, y);
        //STAY(x, y+1, 4); // water którego przesuwamy nadal się updateuje

    } else if (Util.getGrid( DOWN_RIGHT ) == 0) 
    {
        GO_DOWN_RIGHT(x, y);
    } else if (Util.getGrid( DOWN_LEFT ) == 0) 
    {
        GO_DOWN_LEFT(x, y);
    } else {
        STAY(x, y, Util.getGrid( ME ));
    }

}


// void CSand::update(uint16_t x, uint16_t y)
// {

//     if (Util.getGrid( DOWN ) == 0 && Util.getNext( DOWN ) == 0) // down
//     {
//         GO_DOWN(x, y);
//     } else if (Util.getGrid( DOWN ) == 4 || Util.getGrid( DOWN ) == 5 && Util.getNext( DOWN ) == 4 || Util.getNext( DOWN ) == 5)
//     {
//         GO_UP(x, y, Util.getGrid( DOWN ));
//         GO_DOWN(x, y);
//     } else if (Util.getGrid( DOWN_RIGHT ) == 0 && Util.getNext( DOWN_RIGHT ) == 0) // down right
//     {
//         GO_DOWN_RIGHT(x, y);
//     } else if (Util.getGrid( DOWN_LEFT ) == 0 && && Util.getNext( DOWN_LEFT ) == 0) // down left
//     {
//         GO_DOWN_LEFT(x, y);
//     } else {
//         STAY(x, y);
//     }

// }

