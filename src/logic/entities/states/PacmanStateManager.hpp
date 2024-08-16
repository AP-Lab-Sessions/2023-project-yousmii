#ifndef PACMANSTATEMANAGER_HPP
#define PACMANSTATEMANAGER_HPP
#include "PacmanState.hpp"
#include "StateManager.hpp"

namespace Logic {

class PacmanStateManager : public StateManager<PacmanState> {
public:
    explicit PacmanStateManager(PacmanDataPtr pacmanData);
    ~PacmanStateManager() override = default;

    void processStateChanges() override;
};

} // namespace Logic

#endif // PACMANSTATEMANAGER_HPP
