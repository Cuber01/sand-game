#ifndef element_hpp
#define element_hpp

#include <stdint.h>
#include "../utils/data.hpp"


class CElement
{ 
    // protect
    public:

        color_t color;

        CElement();

        virtual void setColor();
        virtual void update(uint16_t x,uint16_t y);
        
};


#endif