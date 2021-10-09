#include "settings.hpp"

#ifdef OPENGL_GUI

    #ifndef gui_hpp
    #define gui_hpp
    
    #include <SDL.h>
    
    #include "imgui.h"
    #include <string>


    class CGUI
    {   
        public:
            bool show_menu_window = false;
            bool show_help_window = false;
            bool show_map_window = false;

            ImGuiIO io;
    
            void init(const char* glsl_version, SDL_GLContext gl_context);
    
            void update();

        private:
            bool collect_file_data = true;

            void collectFileData(std::string path);

            void showMenuWindow();
            void showHelpWindow();
            void showMapWindow();

            uint8_t file_count;
            const char* files[];//ET:size 0 ?
    };
    
    #endif

#endif