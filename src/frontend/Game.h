#ifndef GAME_H
#define GAME_H

#include "states/State.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

/// @brief Singleton class that is responsible for the main loop.
/// @details This class is responsible for the main loop and the state stack. It is the statemanager of the game.
class Game {
private:
    /// @brief Not useable, because this is a singleton class.
    Game();

public:
    /// @brief  Returns the current state of the game.
    /// @return shared pointer to the current state.
    std::shared_ptr<State> getCurrentState();

    /// @brief Pushes a (new) state on the stack.
    /// @param state the new state
    void pushState(std::unique_ptr<State> state);

    /// @brief Pops the current state from the stack.
    void popState();

private:
    /// @brief The window of the game.
    sf::RenderWindow mWindow;

    /// @brief The stack of states.
    std::stack<std::shared_ptr<State>> mStates;

    friend class State; // you're my fren now <3
};

#endif // GAME_H