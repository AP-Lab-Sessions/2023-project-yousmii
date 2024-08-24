#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP

#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class MainMenuState : public State {
public:
    explicit MainMenuState(GameDataPtr data);

    /// @brief Initialize the state, sets the icon, title, and text
    void init() override;

    /// @brief Handle input if the user wants to start the game, either level 1 or 2, or random
    void HandleInput() override;

    /// @brief Update the state, does nothing in this state
    void Update() override;
    void Draw() override;

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
