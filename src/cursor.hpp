#ifndef mouse_hpp
#define mouse_hpp

#include <SDL2/SDL.h>
#include "render.hpp"

class CCursor
{
    public:
        SDL_Rect cursor;
        int x = 20;
        int y = 20;
        int w = 15;
        int h = 15;

        void changeCursor(int x, int y, int w, int h);
};

#endif