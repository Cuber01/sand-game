#include "settings.hpp"

#ifdef OPENGL_GUI

#include <imgui.h>

#include <string>
#include <filesystem>

#include "gui.hpp"
#include "main.hpp"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
using namespace std;



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

    // if (show_map_window) {
    //     showMapWindow();
    // }

    // Rendering
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void CGUI::showMenuWindow()
{
    ImGui::Begin("Slot Editor", &show_menu_window);
        ImGui::Text("Choose which element should appear in each slot.");

        const char* items[] = { "Air", "Cracked Brick", "Dirt", "Fire", "Petrol", "Sand", "Smoke", "Steam", "Wall", "Water", "Wood"};
        static int selected_items[10] = {5, 9, 8, 10, 2, 6, 7, 2, 3, 5};
        
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

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("MouseLeft");
            ImGui::TableNextColumn();
            ImGui::Text("Place current slot");

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("MouseRight");
            ImGui::TableNextColumn();
            ImGui::Text("Remove elements");

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

            // ImGui::TableNextRow();
            // ImGui::TableNextColumn();
            // ImGui::Text("F3");
            // ImGui::TableNextColumn();
            // ImGui::Text("Map Loader");

        
        ImGui::EndTable();
        
        }

        ImGui::Text("MAPS:");
        ImGui::Text("\n");
        ImGui::TextWrapped("Maps are .png images which can be loaded into the game.");
        ImGui::TextWrapped("Every pixel on image represents one cell in the simulation.");
        ImGui::TextWrapped("Maps should be created only with colors from maps/palette.png, other colors will be ignored.");
        
        ImGui::Text("\n");
        
        ImGui::TextWrapped("Maps can be loaded by dropping an image over the window.");

    ImGui::End();
}

// // unused
// void CGUI::showMapWindow()
// {
//     ImGui::Begin("Help", &show_map_window);
//         ImGui::TextWrapped("Select which map would you like to load.");
//         ImGui::Text("\n");
//         ImGui::TextWrapped("For more info press F1.");
//         ImGui::Text("Maps are taken from the maps/ directory.");

//         if(collect_file_data)
//         {
//             std::string path = "/home/cubeq/Projects/cpp/sand_game/out/maps/";
//             // std::string path = "./out/maps/"; //TODO
//             collectFileData(path);
//             collect_file_data = false;
//         }

//         static int selected_item = 0;
//         //printf("%s", files[0]);
        
//         ImGui::Combo("Map",  &selected_item, files, file_count+1);
        
        

//     ImGui::End();
// }

void CGUI::collectFileData(std::string path)
{
    uint8_t file_count = 0U;
    const char* file_name;

    for ( const auto & entry : std::filesystem::directory_iterator(path)) {
        std::string file_name_string = entry.path().u8string();
        file_name = file_name_string.c_str();
        std::cout << file_name;
        //std::cout << file_name_string;
        files[file_count] = file_name;
        file_count++;
    }

    
    
}

#endif