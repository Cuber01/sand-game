OBJS	= src/main.o src/cursor.o src/render.o src/color.o
SOURCE	= src/main.cpp src/cursor.cpp src/render.cpp src/color.cpp
OUT	    = main
CC	    = g++
FLAGS	= -g -c -Wall
LFLAGS	= -lSDL2

all: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(OUT)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

cursor.o: cursor.cpp
	$(CC) $(FLAGS) cursor.cpp

render.o: render.cpp
	$(CC) $(FLAGS) render.cpp

color.o: color.cpp
	$(CC) $(FLAGS) color.cpp

clean:
	rm -f $(OBJS) $(OUT)
