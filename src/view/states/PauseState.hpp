#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class PauseState : public State {
public:
    PauseState(GameDataPtr data);

    void init() override;

    void HandleInput();
    void Update();
    void Draw();

private:
    GameDataPtr _data;

    sf::Text _pauseText;
    sf::Text _resumeText;
    sf::Text _exitText;

    sf::Sprite _resumebutton;
    sf::Sprite _exitbutton;

    void initPauseText();
    void initResumeText();
    void initExitText();
    void initResumeButton();
    void initExitButton();
};

} // namespace View

#endif // PAUSESTATE_HPP
