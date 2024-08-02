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
    sf::Text _title;
    sf::Text _spacetostart;
    sf::Vector2f _centerwindow;

    void initTitle();
    void initSpaceToStart();
    void initIcon();
};

} // namespace View

#endif // SPLASHSTATE_HPP
