#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP

#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class MainMenuState : public State {
public:
    MainMenuState(GameDataRef data);

    void init() override;

    void HandleInput();
    void Update();
    void Draw();

private:
    GameDataRef _data;
    sf::Sprite _icon;
};

} // View

#endif //SPLASHSTATE_HPP
