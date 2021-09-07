#ifndef util_hpp
#define util_hpp

#include <stdint.h>

class CUtil
{
    public:
        CElement* getGrid( uint16_t x, uint16_t y );
        CElement* getNext( uint16_t x, uint16_t y );
        uint8_t random(uint16_t min, uint8_t max);
        bool isOutOfBounds( uint16_t x, uint16_t y );
        


};

#endif