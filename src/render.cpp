#include <SDL.h>
#include <SDL_opengl.h>

#include "elements/element.hpp"
#include "settings.hpp"
#include "utils/data.hpp"
#include "render.hpp"
#include "main.hpp"

#ifdef OPENGL_GUI
#include "gui.hpp"

CGUI GUI;

#endif

void CRenderHandler::init()
{
    #ifdef SOFTWARE_RENDERING
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE); 
    #else
    renderer = SDL_CreateRenderer(window, -1, 0); 
    #endif

    if (renderer == NULL)
    {
        printf("Renderer failed to initialize. Error: %s\n", SDL_GetError());
        exit(1);
    }
    
    surface = SDL_CreateRGBSurface(SDL_SWSURFACE, ROWS, COLS, 32, 0, 0, 0, 0);

    if(surface == NULL) 
    {
        printf("Failed to create surface: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_RenderSetScale(renderer, SCALE, SCALE);

    #ifdef OPENGL_GUI

    #if defined(IMGUI_IMPL_OPENGL_ES2)
        // GL ES 2.0 + GLSL 100
        const char* glsl_version = "#version 100";
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    #elif defined(__APPLE__)
        // GL 3.2 Core + GLSL 150
        const char* glsl_version = "#version 150";
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    #else
        // GL 3.0 + GLSL 130
        const char* glsl_version = "#version 130";
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    #endif

    
    // initialize opengl context
    gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    // SDL_GL_SetSwapInterval(1) TODO vsync;

    GUI.init(glsl_version, gl_context);

    #endif
}


void CRenderHandler::draw()
{
    clear();

    #ifndef SOFTWARE_RENDERING

    // main surface draw loop
    SDL_LockSurface(surface);

    unsigned char* pixels = (unsigned char*)surface -> pixels;
    CElement* value;

    for (uint16_t x = 0; x < ROWS; x++) {
        for (uint16_t y = 0; y < COLS; y++) {

            value = grid[x][y];

            if(value != 0)
            {
                color_t color = value->getColor();

                pixels[4 * (y * surface -> w + x) + 3] = 255;   //opacity

                pixels[4 * (y * surface -> w + x) + 2] = color.r;   //red
                pixels[4 * (y * surface -> w + x) + 1] = color.g;   //green
                pixels[4 * (y * surface -> w + x) + 0] = color.b;   //blue   

            }

        }
    }

    SDL_UnlockSurface(surface);

    // create texture from surface
    texture = SDL_CreateTextureFromSurface(renderer, surface); 
    
    // copy texture over to renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL); 
    
    #endif
     

    #ifdef SOFTWARE_RENDERING

    // main draw loop
    for (uint16_t x = 0; x < ROWS; x++) {
        for (uint16_t y = 0; y < COLS; y++) {
            
            CElement* value = grid[x][y];

            if(value != 0)
            {            

                color_t color = value->getColor();
                //printf("r:%d g:%d b:%d", color.r, color.g, color.b);

                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
                
            }

        }
    }

    #endif

    // draw cursor
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &Cursor.cursor);

    // present render
    //SDL_RenderPresent(renderer);

    #ifdef OPENGL_GUI
    GUI.update();

    SDL_GL_SwapWindow(window);
    #else
    SDL_RenderPresent(renderer);
    #endif

    SDL_DestroyTexture(texture); //TODO keep one texture instead of destroying it every frame, see: SDL_Texture_Lock or SDL_Texture_Update
}

void CRenderHandler::clear()
{
    SDL_FillRect(surface, NULL, 0x000000);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}
    