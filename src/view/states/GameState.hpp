#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../EntityFactory.hpp"
#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class GameState : public State {
public:
    GameState(GameDataPtr data);
    ~GameState(); // Destructs EntityFactory too

    void init() override;

    void HandleInput();
    void Update();
    void Draw();

private:
    GameDataPtr _data;
    sf::RectangleShape _background;
    EntityFactoryPtr _entityFactory;
    // WorldData _world;
};

} // namespace View

#endif // GAMESTATE_HPP
