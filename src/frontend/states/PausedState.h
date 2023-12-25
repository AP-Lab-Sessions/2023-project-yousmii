#ifndef PAUSEDSTATE_H
#define PAUSEDSTATE_H

#include "State.h"

/// @brief Game will be paused in this state and the user will be able to resume the game or quit.
class PausedState : private State {};

#endif // PAUSEDSTATE_H