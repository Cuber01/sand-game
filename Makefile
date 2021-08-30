OBJS	= src/main.o src/particle.o src/mouse.o
SOURCE	= src/main.cpp src/particle.cpp src/mouse.cpp
HEADER	= include/color.hpp
OUT	    = main
CC	    = g++
FLAGS	= -g -c -Wall
LFLAGS	= -lSDL2

all: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(OUT)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

particle.o: particle.cpp
	$(CC) $(FLAGS) particle.cpp

clean:
	rm -f $(OBJS) $(OUT)
