# Use this to compile for web, you need to have emscripten installed on your system
# To use the .html file, do:
# python3.8 -m http.server 8000


OBJS	= $(wildcard src/*.o) $(wildcard src/utils/*.o) $(wildcard src/elements/*.o) $(wildcard src/elements/derived/*.o)

SOURCE	=  $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/elements/*.cpp) $(wildcard src/elements/derived/*.cpp)

# debug:
CFLAGS	= -g -s ALLOW_MEMORY_GROWTH=1 -O3  -s USE_SDL=2

OUT	    = out/sand_game.html
CC	    = emcc
# CFLAGS	= 
LFLAGS	= -lSDL2 

all: $(OBJS)
	$(CC) -o $(OUT) $(SOURCE) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
