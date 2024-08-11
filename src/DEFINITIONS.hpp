#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700
#define SCREEN_TITLE "CPPacman"
#define FRAMERATE_LIMIT 165

#define MONOCRAFT "Monocraft"
#define DSFONT "Pluh"

#define SPRITE_HEIGHT 16 // Within the spritesheet
#define SPRITE_WIDTH 16

#define SPRITE_SCALE 3

#define LEVEL_WIDTH 20
#define LEVEL_HEIGHT 10 // To be respected in the level file, I dont feel like supporting other level sizes

enum class CharacterName { Pacman, Blinky, Pinky, Inky, Clyde };
enum class Direction { RIGHT, LEFT, UP, DOWN };
enum class CollectableName { DOT, FRUIT };
enum class GhostState {NORMAL, FRIGHTENED, CALMING, DEAD};

#endif // DEFINITIONS_HPP
