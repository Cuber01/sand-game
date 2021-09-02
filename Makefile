OBJS	= src/main.o \
src/cursor.o \
src/render.o \
src/utils/data.o \
src/utils/util.o \
src/elements/sand.o \
src/elements/water.o \
src/elements/smoke.o \
src/elements/wood.o \
src/elements/fire.o \

SOURCE	= src/main.cpp \
 src/cursor.cpp \
 src/render.cpp \
 src/utils/data.cpp \
 src/utils/util.cpp \
 src/elements/sand.cpp \
 src/elements/water.cpp \
 src/elements/smoke.cpp \
 src/elements/wood.cpp \
 src/elements/fire.cpp


OUT	    = main
CC	    = g++
CFLAGS	= -g
LFLAGS	= -lSDL2

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(OUT)



clean:
	rm -f $(OBJS) $(OUT)
