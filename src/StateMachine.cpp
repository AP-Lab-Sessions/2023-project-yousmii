// Source: SFML Game Engine series by Sonar Systems on YouTube

#include "StateMachine.hpp"
#include "STATE_LIST.hpp"

namespace View {
StateMachine::StateMachine(GameDataRef data) : _isAdding(false), _isReplacing(false), _isRemoving(false), _data(data) {
    auto splashState = std::make_unique<SplashState>(_data);
    _states.push(std::move(splashState));
}

void StateMachine::AddState(StateRef newState, bool isReplacing) {
    _isAdding = true;
    _isReplacing = isReplacing;
    _newState = std::move(_newState);
}

void StateMachine::RemoveState() { _isRemoving = true; }

void StateMachine::ProcessStateChanges() {
    if (_isRemoving && !_states.empty()) {
        _states.pop();

        if (!_states.empty()) {
            _states.top()->Resume();
        }

        _isRemoving = false;
    }

    if (_isAdding) {
        if (!_states.empty()) {
            if (_isReplacing) {
                _states.pop();
            } else {
                _states.top()->Pause();
            }
        }

        _states.push(std::move(_newState));
        _states.top()->init();
        _isAdding = false;
    }
}

StateRef& StateMachine::GetActiveState() { return _states.top(); }

} // namespace View