# How to compile applications made in SDL2 for Windows, from a Linux machine.

My setup: Ubuntu 20.4, gcc version 9.3.0, SDL version 2.0.10

## mingw64

Install mingw64, by running the following command:
```bash
sudo apt install mingw-w64
```

## SDL2

Clone SDL2 source:
```bash
git clone http://hg.libsdl.org/SDL
cd SDL/
```

Make build/ directory:
```bash
mkdir build
cd build
```

Configure for Windows64bit:
```bash
../configure --prefix=/tmp/sdl2-win64 --host=x86_64-w64-mingw32
```

or

Configure for Windows32bit:
```bash
../configure --prefix=/tmp/sdl2-win64 --host=x86_64-w64-mingw32
```

Make:
```bash
make
make install
```

Now we should get SDL2.dll and other files at /tmp/.

## Build app

For 64bit Windows:
```bash
x86_64-w64-mingw32-g++ test.cpp -I/tmp/sdl2-win64/include/ -L/tmp/sdl2-win64/lib -lmingw32 -lSDL2main -lSDL2 -mwindows -o test.exe
```

or 

For 32bit Windows:
```bash
i686-w64-mingw32-g++ test.cpp -I/tmp/sdl2-win32/include/ -L/tmp/sdl2-win32/lib -lmingw32 -lSDL2main -lSDL2 -mwindows -o test.exe
```

(This is assuming you have ``#include <SDL2/SDL.h>`` in your files)

## Ship app

To ship it, you will need the executable and a few .dll files. If you run your exec it should tell what dlls does it need.

For me (and most basic Windows 64bit SDL applications) it was:
```bash
(path to git cloned SDL)/SDL/build/build/.libs/SDL2.dll
/usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libgcc_s_seh-1.dll
/usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libstdc++-6.dll
```

For 32 bit:
```bash
(path to git cloned SDL)/SDL/build/build/.libs/SDL2.dll
/usr/lib/gcc/i686-w64-mingw32/9.3-win32/libgcc_s_sjlj-1.dll
/usr/lib/gcc/i686-w64-mingw32/9.3-win32/libstdc++-6.dll (very likely)
/usr/i686-w64-mingw32/lib/libwinpthread-1.dll
```

Game I compiled: https://github.com/Cuber01/sand-game
