#ifndef water_hpp
#define water_hpp

#include "../utils/data.hpp"
#include "element.hpp"
#include <stdint.h>


class CWater : public CElement
{
    private:        

        void move(uint16_t x, uint16_t y);
        void spread(uint16_t x, uint16_t y, int8_t right);

        uint8_t dispersionRate = 4;
        bool movesRight;

    public:
        CWater();
        bool doNotUpdate = false; // TODO 
        
        void update(uint16_t x, uint16_t y);

};


#endif