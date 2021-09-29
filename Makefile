# This makefile works if you are on Linux, and would like to make a Linux executable
# It may also work on Mac to compile a Mac executable but I'm not sure

OBJS	= $(wildcard src/*.o) $(wildcard src/utils/*.o) $(wildcard src/elements/*.o) $(wildcard src/elements/derived/*.o)

SOURCE	= $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/elements/*.cpp) $(wildcard src/elements/derived/*.cpp)

# imgui
IMGUI_DIR = ./lib/imgui

SOURCE += $(IMGUI_DIR)/backends/imgui_impl_sdl.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
SOURCE += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp

# debug:
CFLAGS	= -g -ggdb -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends

OUT	    = out/sand_game   
CC	    = g++
LFLAGS	= -lSDL2 -lGL -ldl `sdl2-config --libs`

all: $(OBJS)
	$(CC) -o $(OUT) $(SOURCE) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
