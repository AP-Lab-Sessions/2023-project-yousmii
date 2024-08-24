#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <memory>
#include <stack>

namespace Logic {

template <typename State>
// State manager parent class, has children that manage the states of the ghost and pacman
class StateManager {
public:
    StateManager() = default;
    ~StateManager() = default;

    void addState(std::unique_ptr<State> newState, bool isReplacing = true) {
        _isAdding = true;
        _isReplacing = isReplacing;
        _newState = std::move(newState);
    }

    void removeState() {
        _isRemoving = true;
    }

    void processStateChanges() {
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

    std::unique_ptr<State>& getActiveState() {
        return _states.top();
    }

protected:
    std::stack<std::unique_ptr<State>> _states;
    std::unique_ptr<State> _newState;
    bool _isAdding = false;
    bool _isRemoving = false;
    bool _isReplacing = false;
};

} // namespace Logic

#endif // STATEMANAGER_HPP
