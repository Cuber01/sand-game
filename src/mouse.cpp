#include <SDL2/SDL.h>
#include "main.hpp"

class CMouse
{
    public:
        SDL_Rect cursor;
        int x = 20;
        int y = 20;
        int w = 15;
        int h = 15;

        void changeCursor(int x, int y, int w, int h)
        {
            cursor.x = (x-w)/scale;
            cursor.y = (y-h)/scale;
            cursor.w = w;
            cursor.h = h;
        }
};