OBJS	= src/main.o src/mouse.o src/draw.o src/color.o
SOURCE	= src/main.cpp src/mouse.cpp src/draw.cpp src/color.cpp
OUT	    = main
CC	    = g++
FLAGS	= -g -c -Wall
LFLAGS	= -lSDL2

all: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(OUT)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

mouse.o: mouse.cpp
	$(CC) $(FLAGS) mouse.cpp

draw.o: draw.cpp
	$(CC) $(FLAGS) draw.cpp

color.o: color.cpp
	$(CC) $(FLAGS) color.cpp

clean:
	rm -f $(OBJS) $(OUT)
