#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class GameState : public State {
public:
    GameState(GameDataRef data);

    void init() override;

    void HandleInput();
    void Update();
    void Draw();

private:
    GameDataRef _data;
    sf::RectangleShape _background;
    // Entity viewer goes here, handles positioning, etc. just sends the data to the gamestate
    // EntityViewer _entityViewer;
};

} // namespace View

#endif // GAMESTATE_HPP
