OBJS    = $(wildcard src/*.o) $(wildcard src/*/*.o)

SOURCE    = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)


OUT       = out/sand_game
CC        = g++
CFLAGS    = -Dmain=SDL_main
LFLAGS    = -lmingw32 -lSDL2main -lSDL2

all: $(OBJS)
    $(CC) -o $(OUT) $(SOURCE) $(CFLAGS) $(LFLAGS)

clean:
    rm -f $(OBJS) $(OUT)