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


#ifdef GUI
#include <SDL_opengl.h>

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

const char* glsl_version;
SDL_GLContext gl_context;
ImGuiIO io;
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

    #ifdef GUI

    // initialize opengl
    glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    
    #endif

    // initalize video
    if( SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf( "SDL failed to initialize. Error: %s\n", SDL_GetError() );
        exit(1);
    }

    // setup window
    #ifdef GUI
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

    #ifdef GUI
    // initialize opengl context
    gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1);

    // initalize imgui
    IMGUI_CHECKVERSION(); 
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);
    #endif
    
    // //RenderHandler.init();

}

void quit()
{
    #ifdef GUI
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    #endif

    SDL_DestroyRenderer( RenderHandler.renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}

void handleEvent(SDL_Event* event)
{

    #ifdef GUI
    ImGui_ImplSDL2_ProcessEvent(event);
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

void handleInput()
{
    if(mouseIsPressed)
    {
        if(lastMouseKeyPressed == SDL_BUTTON_LEFT)
        {
            switch (lastKeyboardKeyPressed)
            {
                case KEY_SAND_MODE_NUMKEY1 :
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * SCALE, Cursor.h * SCALE, dSandElement);                
                    break;
                case KEY_WATER_MODE_NUMKEY2 :
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * SCALE, Cursor.h * SCALE, dWaterElement);                
                    break;
                case KEY_WOOD_MODE_NUMKEY3 :
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * SCALE, Cursor.h * SCALE, dWoodElement);                
                    break;
                case KEY_FIRE_MODE_NUMKEY4 :
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * SCALE, Cursor.h * SCALE, dFireElement);
                    break;
                case KEY_SMOKE_MODE_NUMKEY5 :
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * SCALE, Cursor.h * SCALE, dParticleElement);
                    break;
                default:
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * SCALE, Cursor.h * SCALE, dSandElement);
                    break;

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

                    #ifdef DEBUG_STACK
                        stack--;
                    #endif

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

ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
int main(int argc, char* args[])
{
    init();

    RenderHandler.init();

    bool show_another_window = true;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

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
        handleInput();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvent(&event);
        }


        memset( next, 0, sizeof(next) );

        updateParticles();

        RenderHandler.draw(); 

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);


        memcpy( grid, next, sizeof(grid) );

        
    }

    quit();

	return 0;
}
