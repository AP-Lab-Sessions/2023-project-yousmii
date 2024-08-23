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
std::unique_ptr<State>& StateManager<State>::getActiveState() {
    return _states.top();
}

template <typename State>
void StateManager<State>::processStateChanges() {
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

} // namespace Logic