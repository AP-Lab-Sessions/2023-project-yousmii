Project Advanced Programming 2023-2024: CPPacman (C++ Pacman)
=======================================

**Name:** Yousra Smits  
**Student number:** 20201267

Project for the subject Advanced Programming. The project is about 'remaking' Pacman with C++ and SFML.
I learn to apply the principles of object-oriented programming and software design,
while also using smart pointers and the SFML library.

---

## Installation

### Installing dependencies

To install the dependencies, you can use the following command:

```bash
sudo apt-get install -y git cmake gcc g++ libsfml-dev libx11-dev libxrandr-dev libudev-dev libfreetype-dev libopenal-dev libflac-dev libvorbis-dev libxcursor-dev
```

### Cloning the repository

Clone the repository in any way you like.

### Building the project

To build the project, you can use the following commands in the root of the project:

```bash
mkdir build
cd build
cmake ..
make
make install
```

### Running the project

To run the project, you can use the following command in the root of the project:

```bash
./build/cppacman
```

## Implemented Features

| Feature                          | Completed? |
|----------------------------------|------------|
| Game has a start screen          | ✅          |
| Game has a game screen           | ✅          |
| Game has a pause screen          | ✅          |
| Game has custom level files (*)  | ✅          |
| Game has a game over screen (**) | ✅          |
| Simple animations                | ✅          |
| Display score                    | ✅          |
| Display lives                    | ✅          |
| Player can change direction      | ✅          |
| Player can move                  | ✅          |
| Player can eat pellets           | ✅          |
| Player can eat enemies           | ❌          |
| Player can die                   | ❌          |
| Enemies can move                 | ❌          |
| Enemies can kill player          | ❌          |
| Enemies have a setup time        | ❌          |
| Enemies can change from state    | ❌          |

## Known Issues

- Framerate may feel a bit different from the typical Pacman game

## (*): Custom level files

The custom level files are stored in the `assets/levels` folder. With the name `level{n}.lvl` and `{n}` being the level
number.

**The format is as follows:**
- Dimensions of the level are fixed at 20x11 tiles
- Meaning of the characters:
  - `#`: Wall
  - `.`: Pellet
  - `o`: Player/Pacman (only one per level)
  - ` `: Empty space (like the character 'space', the one on your keyboard)
  - `b`: Blinky (red ghost) (only one per level)
  - `p`: Pinky (pink ghost) (only one per level)
  - `i`: Inky (blue ghost) (only one per level)
  - `c`: Clyde (orange ghost) (only one per level)
  - `f`: Fruit (Power up) (only one per level)
- All levels must have a player, a spawn point for the ghosts, at least one pellet and all ghosts. The fruit is
  optional.
- Please note that the level files are case-sensitive
- If you want to change the dimensions of the levels, you can change this in "DEFINITIONS.hpp"

## (**): Game Over Screen

You can easily change to this screen by pressing "Left Alt + F2" for a loss, and "Left Alt + F3" for a win.
This was done for presentation purposes. :)