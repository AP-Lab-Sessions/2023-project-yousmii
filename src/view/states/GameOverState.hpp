
#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP
#include "../State.hpp"
#include "../Game.hpp"

namespace View {

class GameOverState : public State {
public:
    GameOverState(GameDataPtr data, int score, bool win, int level);

    void init() override;
    void HandleInput() override;
    void Update() override;
    void Draw() override;

private:
    void initGameOverText();
    void initScoreText();
    void initInstructionText();

    int _nextlevel;
    GameDataPtr _data;
    sf::Text _gameOverText;
    sf::Text _scoreText;
    sf::Text _instructionText;
};

} // View

#endif //GAMEOVERSTATE_HPP
