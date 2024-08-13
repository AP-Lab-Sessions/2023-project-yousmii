#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include "SETTINGS.hpp" // For the framerate limit

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700
#define SCREEN_TITLE "CPPacman"

#define MONOCRAFT "Monocraft" // Minecraft font but monospaced :)
#define DSFONT "Pluh"         // Don't question it, it might get me in trouble

#define SPRITE_HEIGHT 16 // Within the spritesheet, just handy to have here
#define SPRITE_WIDTH 16
// The scale of the sprites, the sprites are 16x16, so 3x3 is 48x48, fits the screen nicely :)
#define SPRITE_SCALE 3

// To be respected in the level file, I dont feel like supporting other level sizes right now
#define LEVEL_WIDTH 20
#define LEVEL_HEIGHT 10
#define LEVEL_SCALE
#define LEVEL_DIR "assets/levels/"
#define AVAILABLE_LEVELS 2

// Just nice to have here
enum class CharacterName { Pacman, Blinky, Pinky, Inky, Clyde };
enum class Direction { RIGHT, LEFT, UP, DOWN };
enum class CollectableName { DOT, FRUIT };
enum class GhostState {
    NORMAL,
    FRIGHTENED,
    CALMING,
    DEAD
}; // CALMING is when the ghost is almost done being frightened

#endif // DEFINITIONS_HPP
