#ifndef PACMANSTATEMANAGER_HPP
#define PACMANSTATEMANAGER_HPP

#include "PacmanState.hpp"
#include "StateManager.hpp"

namespace Logic {

/// @brief Pacman state manager
class PacmanStateManager : public StateManager<PacmanState> {
    // yea i know, it's empty
};

typedef std::shared_ptr<PacmanStateManager> PacmanStateManagerPtr;

} // namespace Logic

#endif // PACMANSTATEMANAGER_HPP
