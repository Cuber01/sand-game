#ifndef wall_hpp
#define wall_hpp

#include "element.hpp"
#include <stdint.h>

#define wall_color { 179, 179, 179 }

class CWall : public CElement
{

    public:
        CWall();

        void update(uint16_t x, uint16_t y);

        virtual void receiveHeat(float heatAmount);

        void stay(uint16_t x, uint16_t y);

};


#endif