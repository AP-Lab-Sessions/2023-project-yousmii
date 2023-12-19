#ifndef STATES_H
#define STATES_H

#include "../Game.h"
#include <SFML/Graphics.hpp>
#include <memory>

/// @brief The State class is the base class for all states. It is an abstract class.
class State {
protected:
    /// @brief A pointer to the game object.
    std::shared_ptr<Game> mGame;

public:
    /// @brief The constructor for the State class.
    State(std::shared_ptr<Game> game) : mGame(game){};

    /// @brief The destructor for the State class.
    virtual ~State() = 0;

    /// @brief This function is called when the state is entered.
    virtual void onEnter() = 0;

    /// @brief This function is called when the state is exited.
    virtual void onExit() = 0;

    /// @brief This function is called when the state is updated.
    /// @param dt The time that has passed since the last update.
    virtual void update(float dt) = 0;

    /// @brief Renders the window content.
    virtual void render() = 0;

    /// @brief Handles the input events.
    virtual void handleInput(sf::Event event) = 0;
};

#endif // STATES_H