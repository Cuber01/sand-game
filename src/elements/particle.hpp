#ifndef particle_hpp
#define particle_hpp

#include <stdint.h>
#include "element.hpp"

class CParticle : public CElement
{
    
    public:
        CParticle(color_t color, int8_t velocity_x, int8_t velocity_y);

        virtual void update(uint16_t x, uint16_t y);

        void move(uint16_t x, uint16_t y);

        void fly(uint16_t x, uint16_t y, uint16_t target_x, uint16_t target_y);

        void receiveHeat(float heatAmount); 

};

#endif
