#include "settings.hpp"

#ifdef OPENGL_GUI

    #ifndef gui_hpp
    #define gui_hpp
    
    
    #include <SDL.h>
    
    #include "imgui.h"
    
    class CGUI
    {
        public:
            bool show_menu_window = false;
            bool show_help_window = false;
            bool show_map_window = false;

            ImGuiIO io;
    
            void init(const char* glsl_version, SDL_GLContext gl_context);
            
            void showMenuWindow();
            void showHelpWindow();
            void showMapWindow();
    
            void update();
            
    };
    
    #endif

#endif