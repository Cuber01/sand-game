#ifndef fire_hpp
#define fire_hpp

#include "../smoke.hpp"

class CFire : public CSmoke
{
    public:
        // constructor 
        CFire();

        void update(uint16_t x,uint16_t y);

};


#endif