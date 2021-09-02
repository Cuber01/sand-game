#ifndef util_hpp
#define util_hpp

#include <stdint.h>

class CUtil
{
    public:
        uint8_t getGrid( uint16_t x, uint16_t y );
        uint8_t getNext( uint16_t x, uint16_t y );
        uint8_t random(uint8_t min, uint8_t max);
        bool outOfBounds( uint16_t x, uint16_t y );


};

#endif