OBJS	= src/main.o src/cursor.o src/render.o src/color.o src/util.o
SOURCE	= src/main.cpp src/cursor.cpp src/render.cpp src/color.cpp src/util.cpp
OUT	    = main
CC	    = g++
#CFLAGS	= -g -c -Wall
CFLAGS	= -g
LFLAGS	= -lSDL2

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(OUT)

# main.o: main.cpp
# 	$(CC) $(FLAGS) main.cpp

# cursor.o: cursor.cpp
# 	$(CC) $(FLAGS) cursor.cpp

# render.o: render.cpp
# 	$(CC) $(FLAGS) render.cpp

# color.o: color.cpp
# 	$(CC) $(FLAGS) color.cpp

# util.o: util.cpp
# 	$(CC) $(FLAGS) util.cpp

clean:
	rm -f $(OBJS) $(OUT)
