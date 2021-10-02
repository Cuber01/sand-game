#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <memory>
#include <time.h>

#include "main.hpp"
#include "cursor.hpp"
#include "render.hpp"
#include "settings.hpp"
#include "utils/util.hpp"
#include "utils/data.hpp"


#ifdef OPENGL_GUI
#include <SDL_opengl.h>

#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#endif


// sdl
SDL_Window* window = NULL;
SDL_Event event;

#ifdef DEBUG_STACK 
    int stack;
#endif


//int
uint16_t lastKeyboardKeyPressed;
uint8_t  lastMouseKeyPressed;
uint32_t lastId;

element_t elementSlots[10] = {
                            dSandElement, dWaterElement, dWallElement, 
                            dWoodElement, dFireElement, dSmokeElement,
                            dSteamElement, dCrackedBrickElement, dPetrolElement,
                            dParticleElement
                           };

//bool
bool mouseIsPressed = false;
bool running = true;


// grid
CElement* grid[ROWS][COLS];
CElement* next[ROWS][COLS];


// objects
CCursor Cursor;
CRenderHandler RenderHandler;
CUtil Util;

void init()
{

    // place cursor
    Cursor.adjustCursor(20, 20, 40, 40);
    
    // initalize rand
    srand((unsigned)time(NULL));

    // initalize video
    if( SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf( "SDL failed to initialize. Error: %s\n", SDL_GetError() );
        exit(1);
    }

    // setup window
    #ifdef OPENGL_GUI
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    #else 
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_SHOWN);
    #endif

    // create window
	window = SDL_CreateWindow("Sand game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, window_flags);

	if(window == NULL)
	{
		printf( "Window could not be created. SDL_Error: %s\n", SDL_GetError() );
        exit(1);
	} 

    RenderHandler.init();

}

void quit()
{
    #ifdef OPENGL_GUI
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(RenderHandler.gl_context);
    #endif

    SDL_DestroyRenderer( RenderHandler.renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}

void handleEvent(SDL_Event* event)
{

    #ifdef OPENGL_GUI
    ImGui_ImplSDL2_ProcessEvent(event);
    #endif

    if(!ImGui::GetIO().WantCaptureMouse)
    {

        switch (event->type)
        {
        case SDL_MOUSEMOTION:
            SDL_GetMouseState( &Cursor.x, &Cursor.y );
            break;

        case SDL_MOUSEBUTTONDOWN:
            lastMouseKeyPressed = event->button.button;
            mouseIsPressed = true;
            break;

        case SDL_MOUSEBUTTONUP:
            mouseIsPressed = false;
            break;

        case SDL_MOUSEWHEEL:
            if(event->wheel.y > 0) 
            {
                Cursor.w = Cursor.w+2;
                Cursor.h = Cursor.h+2;
            } else if(event->wheel.y < 0) 
            {
                if(Cursor.w >= 3 && Cursor.h >= 3)
                {
                    Cursor.w = Cursor.w - Cursor.change_value;
                    Cursor.h = Cursor.h - Cursor.change_value;
                }
            }
            break;


        case SDL_KEYDOWN:
            lastKeyboardKeyPressed = event->key.keysym.sym;
            break;

        case SDL_QUIT:
            running = false;
            break;

        default:
            break;
        }

   }

}

void reactToEvent()
{
    if(mouseIsPressed)
    {
        if(lastMouseKeyPressed == SDL_BUTTON_LEFT)
        {

            uint16_t x = Cursor.x - Cursor.h;
            uint16_t y = Cursor.y - Cursor.h;
            uint16_t h = Cursor.w * SCALE;
            uint16_t w = Cursor.h * SCALE;

            switch (lastKeyboardKeyPressed)
            {
                case KEY_NUMKEY1 : Cursor.placeParticles(x, y, w, h, elementSlots[0]); break;
                case KEY_NUMKEY2 : Cursor.placeParticles(x, y, w, h, elementSlots[1]); break;
                case KEY_NUMKEY3 : Cursor.placeParticles(x, y, w, h, elementSlots[2]); break;
                case KEY_NUMKEY4 : Cursor.placeParticles(x, y, w, h, elementSlots[3]); break;
                case KEY_NUMKEY5 : Cursor.placeParticles(x, y, w, h, elementSlots[4]); break;
                case KEY_NUMKEY6 : Cursor.placeParticles(x, y, w, h, elementSlots[5]); break;
                case KEY_NUMKEY7 : Cursor.placeParticles(x, y, w, h, elementSlots[6]); break;
                case KEY_NUMKEY8 : Cursor.placeParticles(x, y, w, h, elementSlots[7]); break;
                case KEY_NUMKEY9 : Cursor.placeParticles(x, y, w, h, elementSlots[8]); break;
                case KEY_NUMKEY0 : Cursor.placeParticles(x, y, w, h, elementSlots[9]); break;
                default : Cursor.placeParticles(x, y, w, h, elementSlots[0]); break;
            } 

        } else if (lastMouseKeyPressed == SDL_BUTTON_RIGHT) 
        {
            Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * SCALE, Cursor.h * SCALE, dNoneElement );   
        }   
         
    } else if (lastKeyboardKeyPressed == SDLK_BACKQUOTE)
    {

        for(uint8_t x = 0; x <= ROWS; x++) 
        {
            for(uint8_t y = 0; y <= COLS; y++) 
            {

                if(grid[x][y] != 0)
                {
                    delete grid[x][y];

                    grid[x][y] = 0;
                }

            }
        }

        lastKeyboardKeyPressed = 0;
    }
}

void updateParticles()
{


    for (uint16_t x = 0; x < COLS; x++) {
            for (uint16_t y = 0; y < ROWS; y++) {
                CElement* value = grid[x][y];

                if(value != 0) {


                    value->update(x, y);


                }        
        
            }
    }    


}


int main(int argc, char* args[])
{
    init();

    // Main loop
    while (running)
    {

        #ifdef SLOW
            SDL_Delay(100);
        #endif

        #ifdef DEBUG_STACK
            printf("%d\n", stack);
        #endif

        SDL_Delay(10);


        Cursor.adjustCursor(Cursor.x, Cursor.y, Cursor.w, Cursor.h);   
        reactToEvent();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvent(&event);
        }


        memset( next, 0, sizeof(next) );

        updateParticles();

        RenderHandler.draw(); 

        memcpy( grid, next, sizeof(grid) );

        
    }

    quit();

	return 0;
}
