# Sand game

Sand game is a sandbox game, where you can place one of the many elements and watch them interact with each other.

*Feel free to watch sand.mp4 if you'd like to see how it looks like.*

version 2.0

# Compile instructions

## Install build essentials


To install them with apt, run:
```sh
sudo apt install build-essential
```

If you don't have access to this package you will need to install at least make and g++:
```sh
sudo apt install make g++
```

If you want to, you can also install gdb to run the debug configuration:
```sh
sudo apt install gdb
```

If you don't have access to a fancy package manager, you'll have to get make and g++ in other ways.

## Install SDL dev

To install SDL2 packages, run:
```sh
sudo apt install libsdl2-dev
```

Again, if you don't have access to a package manager and a repository with sdl packages, go to https://wiki.libsdl.org/Installation and check how can you install it on your system.

## Build

Clone the git repo:
```sh
git clone https://github.com/Cuber01/sand-game
```

Clone modules:
```
git submodule update --init
```

Go to dir:
```sh
cd sand-game/
```

Build:
```sh
make
```

Your new executable should be at out/sand-game, if you have any problems, please let me know by opening an issue.

The default scale of the game is 4, you can change it at src/render.hpp (recommended scales: 4, 2, 1).

# Controls

` - Clear board

MouseLeft - Place current slot

MouseRight - Remove elements

1, 2, 3, 4, 5, 6, 7, 8, 9, 0 - Choose Slot

F1 - Show help window (OPENGL_GUI only - currently only on Linux)

F2 - Slot Editor (OPENGL_GUI only - currently only on Linux)

Drop image on window to load a map (MAP_LOADER only - currently only on Linux)


# TODO 

* screen is drawn from 1,1 instead of 0,0
* very big cursor doesnt work properly
* cursor is off

