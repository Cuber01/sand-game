#ifndef water_hpp
#define water_hpp

#include "../utils/data.hpp"
#include "element.hpp"
#include <stdint.h>


class CWater : public CElement
{
    private:
        color_t my_color = { 71, 126, 255 };

        void move(uint16_t x, uint16_t y);

        bool movesRight = true;

    public:
        CWater();
        
        void setColor();
        void update(uint16_t x, uint16_t y);

};


#endif