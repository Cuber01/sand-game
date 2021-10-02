#include "settings.hpp"

#ifdef OPENGL_GUI

#include <imgui.h>

#include "gui.hpp"
#include "main.hpp"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"


void CGUI::init(const char* glsl_version, SDL_GLContext gl_context) {
    // initalize imgui
    IMGUI_CHECKVERSION(); 
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

}

void CGUI::update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

       // printf("%d", GUI.io.WantCaptureMouse);
    
    if (show_test_window)
    {
        ImGui::Begin("Another Window", &show_test_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me"))
            show_test_window = false;
        ImGui::End();
    }

    if (show_menu_window) {
        showMenuWindow();
    }

    // Rendering
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
}

void CGUI::showMenuWindow()
{
    ImGui::Begin("Slot Editor", &show_menu_window);
        ImGui::Text("Choose which element should appear in each slot.");

        const char* items[] = { "Cracked Brick", "Dirt", "Fire", "Particle", "Petrol", "Sand", "Smoke", "Steam", "Wall", "Water", "Wood"};
        static int selected_items[10] = {5, 9, 8, 10, 2, 6, 7, 1, 2, 4};
        
        ImGui::Combo("Slot 1",  &selected_items[0], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 2",  &selected_items[1], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 3",  &selected_items[2], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 4",  &selected_items[3], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 5",  &selected_items[4], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 6",  &selected_items[5], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 7",  &selected_items[6], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 8",  &selected_items[7], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 9",  &selected_items[8], items, IM_ARRAYSIZE(items));
        ImGui::Combo("Slot 10", &selected_items[9], items, IM_ARRAYSIZE(items));

       // ImGui::Text();



    ImGui::End();
}

#endif