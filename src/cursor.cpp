#include <SDL2/SDL.h>
#include "cursor.hpp"

void CCursor::changeCursor(int x, int y, int w, int h)
{
    cursor.x = (x-w)/scale;
    cursor.y = (y-h)/scale;
    cursor.w = w;
    cursor.h = h;
}

