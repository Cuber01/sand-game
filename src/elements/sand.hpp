#ifndef sand_hpp
#define sand_hpp


#include "../utils/data.hpp"
#include "element.hpp"
#include <stdint.h>


class CSand : public CElement
{
    private:

        // whether we check DOWN_RIGHT or DOWN_LEFT first
        bool check_order;

        // direction in which the sand goes after hitting the ground with a high velocity
        int8_t direction;

        // move on the grid
        void move(uint16_t x, uint16_t y);

        // when sand isFalling, it will nudge other sands and set their isFalling to true, which causes a nice chain reaction
        void nudge_neighbors(uint16_t x, uint16_t y);

        // move to left or right with power equal to velocity_y/2 while hitting the ground
        void react_to_velocity_x(uint16_t x, uint16_t y, int8_t direction);

        // fall, taking velocity_y into account
        void fall(uint16_t x, uint16_t y);

    public:
        // constructor 
        CSand();

        // main update loop
        void update(uint16_t x, uint16_t y);

};


#endif