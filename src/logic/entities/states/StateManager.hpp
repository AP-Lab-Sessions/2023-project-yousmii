#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <memory>
#include <stack>

namespace Logic {

template <typename T>
// State manager parent class, has children that manage the states of the ghost and pacman
class StateManager {
public:
    StateManager() = default;
    virtual ~StateManager() = default;

    virtual void addState(std::unique_ptr<T> newState, bool isReplacing = true);

    virtual void removeState();

    virtual void processStateChanges();

    std::unique_ptr<T>& getActiveState();

protected:
    [[nodiscard]] bool isAdding() const { return _isAdding; }
    [[nodiscard]] bool isRemoving() const { return _isRemoving; }
    [[nodiscard]] bool isReplacing() const { return _isReplacing; }

private:
    std::stack<std::unique_ptr<T>> _states;
    std::unique_ptr<std::unique_ptr<T>> _newState;
    bool _isAdding;
    bool _isRemoving;
    bool _isReplacing;
};

} // namespace Logic

#endif // STATEMANAGER_HPP
