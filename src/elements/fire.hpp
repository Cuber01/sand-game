#ifndef fire_hpp
#define fire_hpp

#include <stdint.h>

class CFireHandler
{
    public:
        void update(uint16_t x, uint16_t y);

    private:
        uint8_t spread_chance = 100; // the higher the smaller chance
        uint8_t new_fire_lifetime = 240;

        void handleMovement(uint16_t x, uint16_t y);
        void handleIgnite(uint16_t x, uint16_t y);

};


#endif