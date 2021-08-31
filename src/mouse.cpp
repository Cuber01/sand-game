#include <SDL2/SDL.h>
#include "mouse.hpp"

void CMouse::changeCursor(int x, int y, int w, int h)
{
    cursor.x = (x-w)/scale;
    cursor.y = (y-h)/scale;
    cursor.w = w;
    cursor.h = h;
}

