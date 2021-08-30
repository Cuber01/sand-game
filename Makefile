OBJS	= src/main.o src/mouse.o
SOURCE	= src/main.cpp src/mouse.cpp 
HEADER	= include/color.hpp
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

clean:
	rm -f $(OBJS) $(OUT)
