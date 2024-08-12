#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../EntityFactory.hpp"
#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class GameState : public State {
public:
    GameState(GameDataPtr data, unsigned int level=1);
    ~GameState(); // Destructs EntityFactory too

    void init() override;

    void HandleInput();
    void Update();
    void Draw();

private:
    GameDataPtr _data;
    unsigned int _level;
    sf::RectangleShape _background;
    EntityFactoryPtr _entityFactory;
    // WorldData _world;
};

} // namespace View

#endif // GAMESTATE_HPP
