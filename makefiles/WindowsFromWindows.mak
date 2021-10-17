# Windows from Windows Makefile
# Unmaintained

OBJS    = $(wildcard src/*.o) $(wildcard src/utils/*.o) $(wildcard src/elements/*.o) $(wildcard src/elements/derived/*.o)

SOURCE    = $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/elements/*.cpp) $(wildcard src/elements/derived/*.cpp)

OUT       = out/sand_game.exe
CC        = g++
CFLAGS    = -Dmain=SDL_main
LFLAGS    = -lmingw32 -lSDL2main -lSDL2

all: $(OBJS)
	$(CC) -o $(OUT) $(SOURCE) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)