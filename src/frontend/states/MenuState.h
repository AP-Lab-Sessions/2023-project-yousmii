#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"

/// @brief The MenuState class is responsible for rendering the main menu.
class MenuState : public State{
public:
    /// @brief The constructor for the MenuState class.
    MenuState();
    /// @brief The destructor for the MenuState class.
    virtual ~MenuState();
    /// @brief This function is called when the state is entered.
    virtual void onEnter();
    /// @brief This function is called when the state is exited.
    virtual void onExit();
    /// @brief This function is called when the state is updated.
    /// @param dt The time that has passed since the last update.
    virtual void update(float dt);
    /// @brief This function is called when the state is rendered.
    virtual void render();
};

#endif // MENUSTATE_H