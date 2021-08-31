#include <SDL2/SDL.h>
#include <stdint.h>

#include "cursor.hpp"

void CCursor::adjustCursor(int x, int y, uint8_t w, uint8_t h)
{
    cursor.x = (x-w)/scale;
    cursor.y = (y-h)/scale;
    cursor.w = w;
    cursor.h = h;
}

