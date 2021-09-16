#ifndef sand_hpp
#define sand_hpp

#include "../utils/data.hpp"
#include "element.hpp"
#include <stdint.h>


class CSand : public CElement
{
    public:
        CSand();

        void update(uint16_t x, uint16_t y);
        void move(uint16_t x, uint16_t y);
        void nudge_neighbors(uint16_t x, uint16_t y);

        void fall(uint16_t x, uint16_t y);

};


#endif