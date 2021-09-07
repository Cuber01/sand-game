#ifndef element_hpp
#define element_hpp

#include <stdint.h>
#include "../utils/data.hpp"

class CElement
{
    public:

        color_t color;

        CElement();

        void update(uint16_t x,uint16_t y);

};


#endif