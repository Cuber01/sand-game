#ifndef draw_hpp
#define draw_hpp

#include <inttypes.h>

#define scale 2
extern SDL_Renderer* renderer;

class CDrawing {
    public:
        SDL_Renderer* renderer = NULL;

        void init();
        void draw();
        void clear();

};


#endif