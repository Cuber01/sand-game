# This makefile works if you're on Linux (and perhaps Mac) and would like to compile a Windows executable

OBJS	= $(wildcard src/*.o) $(wildcard src/utils/*.o) $(wildcard src/elements/*.o) $(wildcard src/elements/derived/*.o)

SOURCE	= $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/elements/*.cpp) $(wildcard src/elements/derived/*.cpp)


OUT     = out/sand_game.exe     
CC      = x86_64-w64-mingw32-g++ 
CFLAGS	= 
LFLAGS = -I/tmp/sdl2-win64/include/ -L/tmp/sdl2-win64/lib -lmingw32 -lSDL2main -lSDL2 -mwindows 

all: $(OBJS)
	$(CC) -o $(OUT) $(SOURCE) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)