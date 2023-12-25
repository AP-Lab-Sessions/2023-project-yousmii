#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"

/// @brief The MenuState class is responsible for rendering the main menu.
class MenuState : private State {
private:
    sf::Font font;
    sf::Text title;

public:
    /// @brief The constructor for the MenuState class.
    MenuState(std::shared_ptr<Game> game);

    /// @brief The destructor for the MenuState class.
    ~MenuState() override = default;

    /// @brief This function is called when the state is entered.
    void onEnter() override;

    /// @brief This function is called when the state is exited.
    void onExit() override;

    /// @brief This function is called when the state is updated.
    /// @param dt The time that has passed since the last update.
    void update(float dt) override;

    /// @brief This function is called when the state is rendered.
    void render() const override;
};

#endif // MENUSTATE_H