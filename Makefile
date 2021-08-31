OBJS	= src/main.o src/cursor.o src/render.o src/utils/color.o src/utils/util.o src/elements/sand.o src/elements/water.o
SOURCE	= src/main.cpp src/cursor.cpp src/render.cpp src/utils/color.cpp src/utils/util.cpp src/elements/sand.cpp src/elements/water.cpp
OUT	    = main
CC	    = g++
#CFLAGS	= -g -c -Wall
CFLAGS	= -g
LFLAGS	= -lSDL2

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(OUT)



clean:
	rm -f $(OBJS) $(OUT)
