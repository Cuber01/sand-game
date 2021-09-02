#ifndef mouse_hpp
#define mouse_hpp

#include <SDL2/SDL.h>
#include <stdint.h>

#include "render.hpp"


class CCursor
{
    public:
        SDL_Rect cursor;
        int x = 20; // this has to be an int!
        int y = 20;
        uint8_t w = 3;
        uint8_t h = 3;
        uint8_t change_value = 2;

        void adjustCursor(int x, int y, uint8_t w, uint8_t h);
};

#endif