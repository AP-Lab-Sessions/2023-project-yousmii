#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <memory>
#include <stack>

namespace Logic {

template <typename State>
/// @brief State manager parent class, has children that manage the states of the ghost and pacman
class StateManager {
public:
    StateManager() = default;
    ~StateManager() = default;

    /// @brief Add a state to the stack
    void addState(std::unique_ptr<State> newState, bool isReplacing = true) {
        _isAdding = true;
        _isReplacing = isReplacing;
        _newState = std::move(newState);
    }

    /// @brief Remove the current state
    void removeState() { _isRemoving = true; }

    /// @brief Process state changes, called at the end of the world update
    void processStateChanges() {
        if (_isRemoving && !_states.empty()) {
            _states.pop();
            _isRemoving = false;
        }
        if (_isAdding) {
            if (!_states.empty() && _isReplacing) {
                _states.pop();
            }
            _states.push(std::move(_newState));
            _states.top()->init();
            _isAdding = false;
        }
    }

    /// @brief Get a reference to the current active state
    std::unique_ptr<State>& getActiveState() { return _states.top(); }

protected:
    std::stack<std::unique_ptr<State>> _states;
    std::unique_ptr<State> _newState;
    bool _isAdding = false;
    bool _isRemoving = false;
    bool _isReplacing = false;
};

} // namespace Logic

#endif // STATEMANAGER_HPP
