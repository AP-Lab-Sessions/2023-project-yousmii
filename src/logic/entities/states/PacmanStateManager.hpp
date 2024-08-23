#ifndef PACMANSTATEMANAGER_HPP
#define PACMANSTATEMANAGER_HPP

#include "StateManager.hpp"
#include "PacmanState.hpp"

namespace Logic {

class PacmanStateManager : public StateManager<PacmanState> {
public:
    PacmanStateManager() = default;
    ~PacmanStateManager() override = default;
};

typedef std::shared_ptr<PacmanStateManager> PacmanStateManagerPtr;

} // namespace Logic

#endif // PACMANSTATEMANAGER_HPP
