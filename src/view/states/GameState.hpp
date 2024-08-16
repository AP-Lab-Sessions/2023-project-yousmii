#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../EntityFactory.hpp"
#include "../Game.hpp"
#include "../State.hpp"
#include "../../logic/World.hpp"

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
    void initView();

    GameDataPtr _data;
    int _level;
    std::unique_ptr<Logic::World> _world;
    sf::RectangleShape _background;
    EntityFactoryPtr _entityFactory;
};

} // namespace View

#endif // GAMESTATE_HPP
