#include "../main.hpp"
#include "directions.hpp"
#include "wood.hpp"

#include <stdint.h> 


void CWoodHandler::update(uint16_t x, uint16_t y)
{

    STAY(x, y, Util.getGrid( ME ));

}

