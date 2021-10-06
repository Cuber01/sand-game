# compiler
CC = g++

# compile flags
CFLAGS	:= `sdl2-config --cflags` -g -Wall -Wformat 

# linker flags
LFLAGS = -lSDL2 -lSDL2_image -lGL -ldl `sdl2-config --libs`

# output directory
OUTPUT	= out

# imgui directory
IMGUI_DIR = ./lib/imgui

# source files
SOURCES	= $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/elements/*.cpp) $(wildcard src/elements/derived/*.cpp)

# add imgui files
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp

# include directories
INCLUDES = -I./src/ -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends -I/usr/include/SDL2 

# object files
OBJECTS = $(SOURCES:.cpp=.o)


ifeq ($(OS),Windows_NT)
MAIN	:= sand_game.exe
FIXPATH = $(subst /,\,$1)
RM			:= del /q /f
MD	:= mkdir
else
MAIN	:= sand_game
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p
endif


OUTPUTMAIN	:= $(call FIXPATH,$(OUTPUT)/$(MAIN))

.PHONY: all
all:$(OUTPUTMAIN)
	@echo Executing 'all' complete!

$(OUTPUTMAIN): $(OBJECTS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	@echo Cleanup complete!
