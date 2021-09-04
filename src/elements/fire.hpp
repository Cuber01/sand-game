#ifndef fire_hpp
#define fire_hpp

#include <stdint.h>

class CFireHandler
{
    public:
        void update(uint16_t x, uint16_t y);

    private:
        void handleMovement(uint16_t x, uint16_t y);
        void handleIgnite(uint16_t x, uint16_t y);

};


#endif