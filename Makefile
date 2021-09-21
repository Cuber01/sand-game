OBJS	= $(wildcard src/*.o) $(wildcard src/utils/*.hpp) $(wildcard src/elements/*.o) $(wildcard src/elements/derived/*.cpp)

SOURCE	= $(wildcard src/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/elements/*.cpp) $(wildcard src/elements/derived/*.cpp)


# debug:
CFLAGS	= -g -ggdb

OUT	    = out/sand_game   
CC	    = g++
# CFLAGS	= 
LFLAGS	= -lSDL2 

all: $(OBJS)
	$(CC) -o $(OUT) $(SOURCE) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
