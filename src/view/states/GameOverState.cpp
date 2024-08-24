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

    if(win) {
        _gameOverText.setString("You Win!");
    } else {
        _gameOverText.setString("You lost :(");
    }
    _scoreText.setString("Score: " + std::to_string(score));
}

void GameOverState::init() {
    std::cout << "GameOverState initialised" << std::endl;
    initGameOverText();
    initScoreText();
    initInstructionText();
}

void GameOverState::Draw() {
    _data->window.clear(Color::BLACK);
    _data->window.draw(_gameOverText);
    _data->window.draw(_scoreText);
    _data->window.draw(_instructionText);
    _data->window.display();
}
void GameOverState::initGameOverText() {
    _gameOverText.setFont(_data->assets.GetFont(MONOCRAFT));
    _gameOverText.setCharacterSize(100);
    _gameOverText.setFillColor(Color::CYAN);
    _gameOverText.setOrigin(_gameOverText.getGlobalBounds().width / 2, _gameOverText.getGlobalBounds().height / 2);
    _gameOverText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
}

void GameOverState::initScoreText() {
    _scoreText.setFont(_data->assets.GetFont(MONOCRAFT));
    _scoreText.setCharacterSize(24);
    _scoreText.setFillColor(Color::YELLOW);
    _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
    _scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2 + 100);
}

void GameOverState::initInstructionText() {
    _instructionText.setFont(_data->assets.GetFont(DSFONT));
    _instructionText.setCharacterSize(24);
    _instructionText.setFillColor(Color::WHITE);
    _instructionText.setString("Press Enter to play again or Escape to return to the main menu");
    _instructionText.setOrigin(_instructionText.getGlobalBounds().width / 2,
                               _instructionText.getGlobalBounds().height / 2);
    _instructionText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2 + 130);
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