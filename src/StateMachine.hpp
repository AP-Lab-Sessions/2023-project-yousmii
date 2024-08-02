// Source: SFML Game Engine series by Sonar Systems on YouTube

#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <memory>
#include <stack>

#include "State.hpp"

namespace View {
typedef std::unique_ptr<State> StateRef;

class StateMachine {
public:
    StateMachine() {} // Todo: Make constructor add the splash state
    ~StateMachine() {}

    void AddState(StateRef newState, bool isReplacing = true);
    // isReplacing determines whether the old state is kept on the stack or popped and replaced by the new state
    // This way we can save some memory by no longer keeping the main menu state or the pause menu since these are
    // always the same and can just be reconstructed
    void RemoveState();

    void ProcessStateChanges();

    StateRef &GetActiveState();

private:
    std::stack<StateRef> _states; // States present on the stack
    StateRef _newState; // Latest state to add

    // Track what needs to be done
    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;
};
} // namespace View

#endif // STATEMACHINE_HPP
