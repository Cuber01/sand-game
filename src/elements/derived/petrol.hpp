#ifndef petroleum_hpp
#define petroleum_hpp

#include "../water.hpp"

class CPetrol : public CWater
{
    public:
        // constructor 
        CPetrol();

        void update(uint16_t x, uint16_t y);

        void checkHitpoints(uint16_t x, uint16_t y);

};


#endif