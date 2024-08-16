
#include "PacmanStateManager.hpp"

#include "pacman/PausedState.hpp"

namespace Logic {
PacmanStateManager::PacmanStateManager(PacmanDataPtr pacmanData) {
    addState(std::make_unique<PausedState>(std::shared_ptr<PacmanData>(pacmanData)));
}

void PacmanStateManager::processStateChanges() {
    if (_isRemoving && !_states.empty()) {
        _states.pop();
        _isRemoving = false;
    }
    if (_isAdding) {
        if(!_states.empty() && _isReplacing) {
            _states.pop();
        }
        _states.push(std::move(_newState));
        _states.top()->init();
        _isAdding = false;
    }
}


}
// Logic