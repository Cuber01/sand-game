#ifndef wood_hpp
#define wood_hpp

#include "element.hpp"
#include <stdint.h>

#define wood_color { 75, 27, 5 }

class CWood : public CElement
{
    private:
        void stay(uint16_t x, uint16_t y);

    public:
        CWood();

        void update(uint16_t x, uint16_t y);

        void checkHitpoints(uint16_t x, uint16_t y);

};


#endif