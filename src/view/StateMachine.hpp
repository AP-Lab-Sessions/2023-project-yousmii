// Source: SFML Game Engine series by Sonar Systems on YouTube

#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "State.hpp"

#include <memory>
#include <stack>

namespace View {
typedef std::unique_ptr<State> StateRef;

class StateMachine {
public:
    /// Constructor, does not add any states
    StateMachine() {}
    ~StateMachine() = default;

    /// @brief Add a state to the stack
    /// @param newState The state to add
    /// @param isReplacing Whether to replace the top state or not.
    /// @details The state is added at the start of the next frame
    void AddState(StateRef newState, bool isReplacing = true);

    //// @brief Remove the top state from the stack
    /// @details The state is removed at the start of the next frame
    void RemoveState();

    /// @brief Process state changes, adding, removing, replacing. Called at the start of the frame
    void ProcessStateChanges();

    /// @brief Get the active state reference
    /// @return The active state reference
    /// @remark Please do not store this reference, as it may become invalid and cause undefined behavior
    StateRef& GetActiveState();

private:
    /// Stack of states
    std::stack<StateRef> _states;

    /// State to add
    StateRef _newState;

    // Track what needs to be done
    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;
};
} // namespace View

#endif // STATEMACHINE_HPP
