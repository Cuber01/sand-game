#ifndef water_hpp
#define water_hpp

#include "element.hpp"
#include <stdint.h>

#define _color { 71, 126, 255 } 

class CWater : public CElement
{
    private:
        void move(uint16_t x, uint16_t y);

        bool movesRight = true;

    public:
        CWater();

        void update(uint16_t x, uint16_t y);

};


#endif