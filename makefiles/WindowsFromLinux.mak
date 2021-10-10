SOURCES	= $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/elements/*.cpp) $(wildcard src/elements/derived/*.cpp)
OBJECTS	= $(SOURCES:.cpp=.o)

CC      = x86_64-w64-mingw32-g++ 
CFLAGS	= -std=c++17 -L/tmp/sdl2-win64/lib -g -Wall -Wformat
LFLAGS  = -L/tmp/sdl2-win64/lib -lmingw32 -lSDL2main -lSDL2 -mwindows

INCLUDES = -I./src/ -I/tmp/sdl2-win64/include/ -I/home/cubeq/bin/CompilingOpenSource/SDL/include/
# `sdl2-config --cflags` -I/usr/include/x86_64-linux-gnu/ -I/usr/include/SDL2 -I/usr/lib/gcc/x86_64-w64-mingw32/ `sdl2-config --libs` -L/tmp/sdl2-win64/lib  -L/usr/lib/x86_64-linux-gnu/

ifeq ($(OS),Windows_NT)
FIXPATH = $(subst /,\,$1)
RM			:= del /q /f
MD	:= mkdir out/
else
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p out/
endif

# output directory
OUTPUT	= out

# executable
MAIN	:= sand_game.exe

# full output path
OUTPUTMAIN	:= $(OUTPUT)/$(MAIN)

$(OUTPUTMAIN): $(OBJECTS) 
	$(MD)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS)

.cpp.o:
	$(MD)
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) -c $<  -o $@ 

# all: $(OBJECTS)
# 	@echo "INCLUDES"
# 	$(CC) -o $(OUT) $(SOURCES) $(CFLAGS) $(INCLUDES) $(LFLAGS)

# clean:
# 	rm -f $(OBJECTS) $(OUT)

# -----------------------------


# # output directory
# OUTPUT	= out

# # executable
# MAIN	:= sand_game.exe

# # full output path
# OUTPUTMAIN	:= $(OUTPUT)/$(MAIN)


# OUT     = out/sand_game.exe     
# CC      = x86_64-w64-mingw32-g++ 
# CFLAGS	= -std=c++17 `sdl2-config --cflags` -g -Wall -Wformat 
# LFLAGS  = -L/tmp/sdl2-win64/lib -L/usr/lib/x86_64-linux-gnu/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows 

# # include directories
# INCLUDES = -I./src/ -I/usr/include/SDL2 -I/tmp/sdl2-win64/include/SDL2/ -I/usr/lib/gcc/x86_64-w64-mingw32/ -I/usr/include/x86_64-linux-gnu/ #-I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends 

# $(OUTPUTMAIN): $(OBJECTS) 
# 	$(MD)
# 	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS)

# .cpp.o:
# 	$(MD)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@



# .PHONY: all
# all:$(OUTPUTMAIN)
# 	@echo $(OUTPUTMAIN)
# 	@echo Executing 'all' complete!

# .PHONY: clean
# clean:
# 	$(RM) $(OUTPUTMAIN)
# 	$(RM) $(call FIXPATH,$(OBJECTS))
# 	@echo Cleanup complete!
	


# # compile flags
# CFLAGS	:= -std=c++17 `sdl2-config --cflags` -g -Wall -Wformat -I/usr/lib/gcc/x86_64-w64-mingw32/ -lmingw32 -lSDL2main -lSDL2 -mwindows

# # linker flags
# LFLAGS = -lSDL2 -lSDL2_image -lGL -ldl `sdl2-config --libs` -I/tmp/sdl2-win64/include/ -L/tmp/sdl2-win64/lib -lmingw32 -lSDL2main -lSDL2 -mwindows 

# # imgui directory
# IMGUI_DIR = ./lib/imgui

# # add imgui files
# #SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
# #SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp

