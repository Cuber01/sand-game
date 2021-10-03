# Use this to compile for web, you need to have emscripten installed on your system

# OPENG_GUI has to be undefined
# __EMSCRIPTEN has to be defined

# To use the .html file, do:
# python3.8 -m http.server 8000
IMGUI_DIR = ./lib/imgui

OBJS	= $(wildcard src/*.o) $(wildcard src/utils/*.o) $(wildcard src/elements/*.o) $(wildcard src/elements/derived/*.o)

SOURCES	=  $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/elements/*.cpp) $(wildcard src/elements/derived/*.cpp)

SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp

# include directories
INCLUDES = -I./src/ -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends -I/usr/include/SDL2 -I./lib


# debug:
CFLAGS	= -g -s ALLOW_MEMORY_GROWTH=1 -O3 -s USE_SDL=2 -s OFFSCREEN_FRAMEBUFFER=1 

OUT	    = out/sand_game.html
CC	    = emcc
# CFLAGS	= 
LFLAGS	= -lSDL2 

all: $(OBJS)
	$(CC) -o $(OUT) $(SOURCES) $(CFLAGS) $(INCLUDES) $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
