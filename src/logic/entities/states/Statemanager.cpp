#include "StateManager.hpp"

namespace Logic {

template <typename State>
void StateManager<State>::addState(std::unique_ptr<State> newState, bool isReplacing) {
    _isAdding = true;
    _isReplacing = isReplacing;
    _newState = std::move(newState);
}

template <typename State>
void StateManager<State>::removeState() {
    _isRemoving = true;
}

template <typename State>
void StateManager<State>::processStateChanges() {
} // Best I define it in the child classes since it has to move data sometimes

template <typename State>
std::unique_ptr<State>& StateManager<State>::getActiveState() {
    return _states.top();
}

} // namespace Logic