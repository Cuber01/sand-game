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
#include "map_loader.hpp"


#ifdef OPENGL_GUI
#include <SDL_opengl.h>

#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#endif

#ifdef __EMSCRIPTEN
    #include <emscripten.h>
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
CmapLoader MapLoader;


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

    if(!ImGui::GetIO().WantCaptureMouse)
    {
    #endif


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
        }

    #ifdef OPENGL_GUI   
    }
    #endif

    switch (event->type)
    {

    case SDL_KEYDOWN:
        lastKeyboardKeyPressed = event->key.keysym.sym;
        break;

    case SDL_QUIT:
        running = false;
        break;

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
         
    } else 
    {

        switch (lastKeyboardKeyPressed)
        {
        
            case SDLK_BACKQUOTE:    
                Util.clearGrid();
                lastKeyboardKeyPressed = 0;
                break;

            #ifdef OPENGL_GUI

            case SDL_SCANCODE_F1:
                GUI.show_help_window = !GUI.show_help_window;
                lastKeyboardKeyPressed = 0;
                break;

            case SDL_SCANCODE_F2:
                GUI.show_menu_window = !GUI.show_menu_window;
                lastKeyboardKeyPressed = 0;
                break;

            case SDL_SCANCODE_F3:
                GUI.show_map_window = !GUI.show_map_window;
                lastKeyboardKeyPressed = 0;
                break;

            #endif

            default:
                break;
        }

    }
}

void updateParticles()
{

    for (uint16_t y = 0; y < ROWS; y++) {
                

        for (uint16_t x = 0; x < COLS; x++) {
         
            CElement* value = grid[x][y];
            if(value != 0) {


                value->update(x, y);


            }        
        
        }    

    }

}

void main_loop()
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

int main(int argc, char* args[])
{
    init();

    MapLoader.loadMap("/home/cubeq/Projects/cpp/sand_game/out/maps/map1.png");

    #ifdef __EMSCRIPTEN
        emscripten_set_main_loop(main_loop, 0, 1);
    #else

    while(running)
    {
        main_loop();
    }
            
    #endif

    quit();

	return 0;
}
