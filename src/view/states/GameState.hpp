#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class GameState : public State {
public:
    GameState(GameDataPtr data);

    void init() override;

    void HandleInput();
    void Update();
    void Draw();

private:
    GameDataPtr _data;
    sf::RectangleShape _background;
    // Entity viewer goes here, handles positioning, etc. just sends the data to the gamestate
    // EntityViewer _entityViewer;
};

} // namespace View

#endif // GAMESTATE_HPP
