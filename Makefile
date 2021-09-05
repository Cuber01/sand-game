OBJS	= $(wildcard src/*.o) $(wildcard src/*/*.o)


SOURCE	= $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)


# debug:
# CFLAGS	= -g -ggdb


OUT	    = out/sand_game
CC	    = g++
CFLAGS	= 
LFLAGS	= -lSDL2

all: $(OBJS)
	$(CC) -o $(OUT) $(SOURCE) $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
