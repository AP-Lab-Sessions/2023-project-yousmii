// Source: SFML Game Engine series by Sonar Systems on YouTube

#include "StateMachine.hpp"
#include "STATE_LIST.hpp"

namespace View {

void StateMachine::AddState(StateRef newState, bool isReplacing) {
    if (newState == nullptr) {
        throw std::invalid_argument("StateMachine::AddState: newState is nullptr");
    }
    _isAdding = true;
    _isReplacing = isReplacing;
    _newState = std::move(newState);
}

void StateMachine::RemoveState() { _isRemoving = true; }

void StateMachine::ProcessStateChanges() {
    if (_isRemoving && !_states.empty()) { // If we are removing a state
        _states.pop();

        if (!_states.empty()) { // If there are still states in the stack
            _states.top()->Resume();
        }

        _isRemoving = false; // We are no longer removing a state
    }

    if (_isAdding) { // If we are adding a state
        if (!_states.empty()) { // If there are still states in the stack
            if (_isReplacing) { // If we are replacing the current state
                _states.pop(); // Remove the current state
            } else {
                _states.top()->Pause(); // No real functionality here, I added this just in case we need to do something when a state is added
            }
        }

        _states.push(std::move(_newState)); // Add the new state to the stack, best moved here to avoid dangling pointers
        _states.top()->init();
        _isAdding = false; // We are no longer adding a state
    }
}

StateRef& StateMachine::GetActiveState() { return _states.top(); } // Return the current state

} // namespace View