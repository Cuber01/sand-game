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

## Change settings

You can tweak a few compile settings at src/settings.hpp 

*Please note that the default settings should be fine for most setups.*


The important ones are:

``#define SOFTWARE_RENDERING`` - if this is defined, we use some sort of software rendering, and draw every pixel on screen using SDL_RenderDrawPoint. This performs ok on Linux but terribly on Windows. If this is not defined, we edit a texture and then draw it on screen. You should probably keep it disabled.

``#define SCALE 6`` - scale of the game. Example: if it's 6, every cell is a 6x6 square.

``#define OPENGL_GUI`` - if this is defined, we use imgui and opengl to draw gui in the game (F1, F2). The Linux to Linux Makefile (the default one), can handle this, however I still haven't managed to compile with gui for Windows or Web, so if you use my Makefile for Windows/Web, make sure to keep it undefined.

``#define MAP_LOADER`` - if this is defined, you can drop an image on the game's window, to load it as a map. For more info press F1. The Linux to Linux Makefile (the default one), can handle this, however I still haven't managed to compile with map loader for Windows or Web, so if you use my Makefile for Windows/Web, make sure to keep it undefined.

``#define __EMSCRIPTEN`` - if you're compiling for web, make sure to enable it, if you're not compiling on web, comment it out.

## Choose a Makefile

Yep, I don't have a universal Makefile. Sorry.

Makefiles are kept at makefiles/

1. If you're compiling from Linux to Linux: Go with the default one (maintained)
2. If you're compiling from Linux to Windows: use makefiles/WindowsFromLinux.mak (maintained)
3. If you're compiling from Windows to Windows: use makefiles/WindowsFromWindows.mak (unmaintained)
4. If you're compiling from Linux to Web: use makefiles/Web.mak (maintained)

Choose yours and put it in the root directory.
Read their comments for further instructions.


I'm having quite some trouble with developing on multiple platforms, so if you want to, I'd be really happy if you could help me out.  Read Contributing.md for more info.

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

# Contributing

If you'd like to contribute to the project, read Contributing.md

I have a lot of trouble in maintaining makefiles for multiple platforms, so help in that field is even more appreciated.

# Contact

The best way to contact me at the moment, is the [issue board](https://github.com/Cuber01/sand-game/issues).
Feel free to ask any questions or report bugs there.

