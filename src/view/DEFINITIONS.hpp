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

enum class CharacterName { Pacman, Blinky, Pinky, Inky, Clyde };
enum class Direction { RIGHT, LEFT, UP, DOWN };
enum class CollectableName { DOT, FRUIT };
enum class GhostState {NORMAL, FRIGHTENED, CALMING, DEAD};

#endif // DEFINITIONS_HPP
