#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../../logic/World.hpp"
#include "../EntityFactory.hpp"
#include "../Game.hpp"
#include "../State.hpp"

namespace View {

class GameState : public State {
public:
    GameState(GameDataPtr data, int level = 1);
    ~GameState(); // TODO: Destruct EntityFactory too

    void init() override;

    void HandleInput();
    void Update();
    void Draw();

    void updateScore();
    void updateLives();

private:
    void initView();

    GameDataPtr _data;
    int _level;
    std::unique_ptr<Logic::World> _world;
    sf::RectangleShape _background;
    EntityFactoryPtr _entityFactory;
    sf::Text _scoreText;
    sf::Text _livesText;
};

} // namespace View

#endif // GAMESTATE_HPP
