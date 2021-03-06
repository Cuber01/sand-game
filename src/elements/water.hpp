#ifndef water_hpp
#define water_hpp

#include "../utils/data.hpp"
#include "element.hpp"
#include <stdint.h>


class CWater : public CElement
{
    private:        

        void spread(uint16_t x, uint16_t y, int8_t right);

        uint8_t dispersionRate = 8;
        bool movesRight;

    public:
        CWater();

        void move(uint16_t x, uint16_t y);
        void fall(uint16_t x, uint16_t y);
        
        virtual void update(uint16_t x, uint16_t y);


};


#endif