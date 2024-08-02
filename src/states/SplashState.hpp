#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP

#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class SplashState : public State {
public:
    SplashState(GameDataRef data);

    void init() override;

    void HandleInput();
    void Update(double dt);
    void Draw(double dt);

private:
    GameDataRef _data;
    sf::Sprite _icon;
};

} // View

#endif //SPLASHSTATE_HPP
