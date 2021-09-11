#ifndef draw_hpp
#define draw_hpp

#include <stdint.h>

extern SDL_Renderer* renderer;

class CRenderHandler {
    public:
        SDL_Renderer* renderer = NULL;

        void init();
        void draw();
        void clear();

};


#endif