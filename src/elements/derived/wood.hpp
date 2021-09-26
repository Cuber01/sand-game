#ifndef wood_hpp
#define wood_hpp

#include "../wall.hpp"
#include <stdint.h>

#define wood_color { 75, 27, 5 }

class CWood : public CWall
{

    public:
        CWood();

        void update(uint16_t x, uint16_t y);

        void checkHitpoints(uint16_t x, uint16_t y);

        void receiveHeat(float heatAmount);

};


#endif