# Sand game

Sand game is a sandbox game, where you can place one of the 5 elements available (sand, water, wood, smoke and fire) and watch them interact with each other.

*Feel free to watch sand.mp4 if you'd like to see how it looks like.*

You're currently on the 'simple' branch (if you're on master and there is no 'simple' branch, this means that I still haven't started working on the rewrite and you can clone master), I would like to rewrite this project in full OOP and add better interactions on the master branch.

version 1.0

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

Go to dir and create out/ directory:
```sh
cd sand-game/
mkdir out/
```

Build:
```sh
make
```

Your new executable should be at out/sand-game, if you have any problems, please let me know by opening an issue.

The default scale of the game is 4, you can change it at src/render.hpp (recommended scales: 4, 2, 1).

# Controls

1 - choose sand

2 - choose water

3 - choose wood

4 - choose fire

5 - choose smoke

` - clear the board

Any other keyboard button will result in choosing sand.

Left mouse button - place chosen particle

Right mouse button - remove particles

Mouse wheel - change cursor size

# For code-readers and fellow developers

So, it turns out that you simply **can't** make a complex sand game while keeping all the info about a cell in a number. That's why, very often, there are dumb hardcoded things in the code.

But anyways, here's how it works:

You get a 2d array with numbers, every number is an element:
* 1-3 - different colors of sand
* 4 - water moving right
* 5 - water moving left
* 6 - wood
* 7 - smoke
* 8-254 - fire 
* 255 - fake water (when sand goes into the water, it places fake water, which dies after one frame, so real water will not take the place where sand is supposed to fall)

In src/utils/data.cpp there's a list of colors. When drawing our particles we usually do (pseudocode):
```
color = color_list[value]
```

If it's fire (which changes colors every frame), we randomly choose between 8, 9 and 10.

If it's fake water, we use 4 (water color).

Fake water is a terrible system I added a while ago, but again, because of the fact I keep everything in numbers on an array it's the only way I could think of.

Next, we update particles with rules.


## Rules for elements:
Only one rule can be true.


Sand:
* check down (if empty move)
* check down left(if empty move)
* check down right(if empty move)
* stay

Water: 
* check down (if empty move)
* check down left (if empty move)
* check down right (if empty move)
* check left and right (if both empty: if I'm 4, move right, if I'm 5, move left) 
* check right (if empty move)
* check left (if empty move)
* stay

Wood:
* stay

Smoke:
* check up (if empty: chance to move)
* check up left (if empty: chance to move)
* check up right (if empty: chance to move)
* check right (if empty: chance to move)
* check left (if empty: chance to move)
* stay

Fire:
* check up (if empty: chance to move and decrement)
* check up left (if empty: chance to move and decrement)
* check up right (if empty: chance to move and decrement)
* check right (if empty: chance to move and decrement)
* check left (if empty: chance to move and decrement)
* stay
  
After that:

* check all neighboring cells in search for wood (if wood: small chance to spawn fire on wood)

After some time, Fire will decrement itself to Smoke.


# TODO 

* screen is drawn from 1,1 instead of 0,0
* add clear
* very big cursor doesnt work properly
