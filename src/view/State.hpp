#ifndef STATE_HPP
#define STATE_HPP

#include "COLORS.hpp"

namespace View { // Representation
class State {
public:
    virtual ~State() = default;
    /// @brief Initialize the state
    virtual void init() = 0;

    /// @brief Handle input
    virtual void HandleInput() = 0;

    /// @brief Update the state
    virtual void Update() = 0;

    /// @brief Draw the sprites and text onto the window
    virtual void Draw() = 0;

    /// @brief Pause the state, not used in this project
    virtual void Pause() {}

    /// @brief Resume the state, not used in this project
    virtual void Resume() {}
};
} // namespace View

#endif // STATE_HPP
