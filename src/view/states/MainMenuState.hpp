#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP

#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class MainMenuState : public State {
public:
    MainMenuState(GameDataPtr data);

    void init() override;

    void HandleInput();
    void Update();
    void Draw();

private:
    GameDataPtr _data;
    sf::Sprite _icon;
    sf::Text _title;
    sf::Text _spacetostart;
    sf::Text _level1Start;
    sf::Text _level2Start;

    sf::Vector2f _centerwindow;

    void initTitle();
    void initSpaceToStart();
    void initIcon();
    void initLevel1Start();
    void initLevel2Start();
};

} // namespace View

#endif // SPLASHSTATE_HPP
