#include "GameOverState.hpp"

#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

namespace View {
GameOverState::GameOverState(GameDataPtr data, int score, bool win, int level) : _data(data) {
    if (level == AVAILABLE_LEVELS) {
        _nextlevel = 1;
    } else {
        _nextlevel = level + 1;
    }

    _scoreText.setFont(_data->assets.GetFont(DSFONT));
    _scoreText.setCharacterSize(24);
    _scoreText.setFillColor(Color::YELLOW);
    _scoreText.setPosition(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50);
    _scoreText.setString("Score: " + std::to_string(score));

    _gameOverText.setFont(_data->assets.GetFont(MONOCRAFT));
    _gameOverText.setCharacterSize(60);
    _gameOverText.setFillColor(Color::YELLOW);
    _gameOverText.setPosition(SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 200);

    if(win) {
        _gameOverText.setString("You Win!");
    } else {
        _gameOverText.setString("Game Over");
    }

    _instructionText.setFont(_data->assets.GetFont(DSFONT));
    _instructionText.setCharacterSize(24);
    _instructionText.setFillColor(Color::YELLOW);
    _instructionText.setPosition(SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 + 50);
    _instructionText.setString("Press Enter to play the next level or Esc to quit");
}

void GameOverState::init() {
    std::cout << "GameOverState initialised" << std::endl;
}

void GameOverState::Draw() {
    _data->window.clear(Color::BLACK);
    _data->window.draw(_gameOverText);
    _data->window.draw(_scoreText);
    _data->window.draw(_instructionText);
    _data->window.display();
}

void GameOverState::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        _data->machine.AddState(StateRef(new GameState(_data, _nextlevel)), true);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
    }
}
void GameOverState::Update() {}

} // View