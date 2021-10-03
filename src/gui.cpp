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

    #ifdef __EMSCRIPTEN
    io.IniFilename = NULL;
    #endif
    


    ImGui::StyleColorsDark();


    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

}

void CGUI::update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    if (show_menu_window) {
        showMenuWindow();
    }

    if (show_help_window) {
        showHelpWindow();
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

        const char* items[] = { "Air", "Cracked Brick", "Dirt", "Fire", "Particle", "Petrol", "Sand", "Smoke", "Steam", "Wall", "Water", "Wood"};
        static int selected_items[10] = {6, 10, 9, 11, 3, 7, 8, 2, 3, 5};
        
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

    ImGui::End();

    for(uint8_t i = 0; i < 10; i++)
    {
        elementSlots[i] = static_cast<element_t>(selected_items[i]);
    }
}

void CGUI::showHelpWindow()
{
    ImGui::Begin("Help", &show_help_window);
        ImGui::Text("SAND GAME 2021 @Cuber01");
        ImGui::Text("\n");
        ImGui::TextWrapped("Cell based sandbox simulation in which you can place many particles and watch them interact with each other.");
        ImGui::Text("\n");
        ImGui::Text("CONTROLS:");
        ImGui::Text("\n");

        if (ImGui::BeginTable("table2", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
        {

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("`");
            ImGui::TableNextColumn();
            ImGui::Text("Clear board");

            for(uint8_t i = 0; i <= 9; i++)
            {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%d", i);
                ImGui::TableNextColumn();
                ImGui::Text("Select slot %d", i);
            }

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("F1");
            ImGui::TableNextColumn();
            ImGui::Text("Help");

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("F2");
            ImGui::TableNextColumn();
            ImGui::Text("Slot Editor");


            
        
        ImGui::EndTable();
        
        }

    ImGui::End();
}

#endif