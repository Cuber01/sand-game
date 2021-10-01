#include "settings.hpp"

#ifdef OPENGL_GUI

    #ifndef gui_hpp
    #define gui_hpp
    
    
    #include <SDL.h>
    
    #include "imgui.h"
    
    class CGUI
    {
        public:
            bool show_test_window = true;
            ImGuiIO io;
    
            void init(const char* glsl_version, SDL_GLContext gl_context);
            
            void showMenuWindow();
    
            void update();
            
    };
    
    #endif

#endif