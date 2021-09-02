#include <SDL2/SDL.h>
#include <stdint.h>

#include "cursor.hpp"

void CCursor::adjustCursor(int x, int y, uint8_t w, uint8_t h)
{
    cursor.x = (x-(w*(scale/2)))/scale;
    cursor.y = (y-(h*(scale/2)))/scale;
    cursor.w = w;
    cursor.h = h;
}

