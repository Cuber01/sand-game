#include <SDL2/SDL.h>

class CMouse
{
    public:
        SDL_Rect cursor;
        int x = 20;
        int y = 20;
        int w = 30;
        int h = 30;

        void changeCursor(int x, int y, int w, int h)
        {
            cursor.x = x-w/2;
            cursor.y = y-h/2;
            cursor.w = w;
            cursor.h = h;
        }
};