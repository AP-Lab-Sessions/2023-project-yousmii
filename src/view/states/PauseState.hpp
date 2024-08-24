#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class PauseState : public State {
public:
    explicit PauseState(GameDataPtr data);

    void init() override;

    /// @brief Handle input if the user wants to resume or exit the game
    void HandleInput() override;

    /// @brief Update the state, does nothing in this state
    void Update() override;

    /// @brief Draw the sprites and text onto the window
    void Draw() override;

private:
    GameDataPtr _data;

    sf::Text _pauseText;
    sf::Text _resumeText;
    sf::Text _exitText;

    /// @brief Initialize the pause text
    void initPauseText();
    /// @brief Initialize the resume text
    void initResumeText();
    /// @brief Initialize the exit text
    void initExitText();
};

} // namespace View

#endif // PAUSESTATE_HPP
