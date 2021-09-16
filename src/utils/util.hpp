#ifndef util_hpp
#define util_hpp

#include <stdint.h>

class CUtil
{
    public:
        // this is returned by get function when they encounter a bound, to indicate that it is not an empty space
        CElement bounds;

        CElement* getGrid( uint16_t x, uint16_t y );
        CElement* getNext( uint16_t x, uint16_t y );
        uint8_t random(uint16_t min, uint8_t max);
        int8_t randomPositiveNegative();
        bool isOutOfBounds( uint16_t x, uint16_t y );
        


};

#endif