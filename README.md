Project Advanced Programming 2023-2024
=======================================

**Name:** Yousra Smits  
**Student number:** 20201267

Project for the subject Advanced Programming. The project is about 'remaking' Pacman with C++ and SFML. I learn to apply
the principles of object-oriented programming and software design.
There is also usage of threads and mutexes.
---

## Installation

## Features

### Implemented

- Game has a start screen, game screen and pause screen
- The game has a player and enemies
- The entities are animated
- Custom level files can be loaded with a fixed size and format

### Planned

| Feature                         | Completed? |
|---------------------------------|------------|
| Game has a start screen         | ✅          |
| Game has a game screen          | ✅          |
| Game has a pause screen         | ✅          |
| Game has a game over screen     | ❌          |
| Game has custom level files (*) | ✅          |
| Simple animations               | ✅          |
| Display score                   | ❌          |
| Display lives                   | ❌          |
| Player can change direction     | ❌          |
| Player can move                 | ❌          |
| Player can eat pellets          | ❌          |
| Player can eat enemies          | ❌          |
| Player can die                  | ❌          |
| Enemies can move                | ❌          |
| Enemies can kill player         | ❌          |
| Enemies have a setup time       | ❌          |
| Enemies can change from state   | ❌          |

## Known Issues

- Framerate may feel a bit different from the typical Pacman game. Still working on perfecting that

## (*): Custom level files

The custom level files are stored in the `assets/levels` folder. With the name `level{n}.lvl` The format is as follows:

- Dimensions of the level are fixed at 20x11 tiles
- Meaning of the characters:
  - `#`: Wall
  - `.`: Pellet
  - `o`: Player
  - ` `: Empty space (like the character 'space', the one on your keyboard)
  - `g`: (Re)spawn point for the ghost
  - `b`: Blinky (red ghost)
  - `p`: Pinky (pink ghost)
  - `i`: Inky (blue ghost)
  - `c`: Clyde (orange ghost)
  - `f`: Fruit (Power up)
- Please note that the level files are case-sensitive
- If you want to change the dimensions of the levels, you can change this in "DEFINITIONS.hpp"