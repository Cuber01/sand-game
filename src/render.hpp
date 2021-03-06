#ifndef draw_hpp
#define draw_hpp

#include "settings.hpp"
#include <stdint.h>
#include "gui.hpp"

#ifdef OPENGL_GUI
extern CGUI GUI;
#endif

extern SDL_Renderer* renderer;

class CRenderHandler {
    public:
        SDL_Renderer* renderer = NULL;
        SDL_Surface* surface = NULL;
        SDL_Texture* texture = NULL;

        const char* glsl_version;
        SDL_GLContext gl_context;

        void init();
        void draw();
        void clear();

};


#endif