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
    virtual ~StateManager() = default;

    void addState(std::unique_ptr<State> newState, bool isReplacing = true);

    void removeState();

    virtual void processStateChanges();

    std::unique_ptr<State>& getActiveState();

protected:
    std::stack<std::unique_ptr<State>> _states;
    std::unique_ptr<State> _newState;
    bool _isAdding = false;
    bool _isRemoving = false;
    bool _isReplacing = false;
};

} // namespace Logic

#endif // STATEMANAGER_HPP
