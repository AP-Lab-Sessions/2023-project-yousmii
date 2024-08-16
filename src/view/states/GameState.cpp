#include "GameState.hpp"
#include "PauseState.hpp"

#include <utility>

namespace View {
GameState::GameState(GameDataPtr data, unsigned int level) : _data(std::move(data)), _level(level) {
    if (_level > AVAILABLE_LEVELS) {
        _level = 1;
    }
    _world = std::make_unique<Logic::World>(_level);
    EntityFactoryPtr entityFactory(new EntityFactory(_data->assets.GetTexture("Sprites"), _world->GetFullMap()));
    _entityFactory = std::move(entityFactory);
}

void GameState::init() {
    std::cout << "GameState initialised" << std::endl;
    _background.setSize(sf::Vector2f(LEVEL_WIDTH * TILE_SIZE, LEVEL_HEIGHT * TILE_SIZE));
    _background.setPosition(0, 0);
    _background.setFillColor(sf::Color::Black);

    _scoreText.setFont(_data->assets.GetFont(MONOCRAFT));
    _scoreText.setCharacterSize(24);
    _scoreText.setFillColor(Color::YELLOW);
    _scoreText.setPosition(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 50);

    _livesText.setFont(_data->assets.GetFont(MONOCRAFT));
    _livesText.setCharacterSize(24);
    _livesText.setFillColor(Color::YELLOW);
    _livesText.setPosition(20, SCREEN_HEIGHT - 50);
}

void GameState::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        _data->machine.AddState(StateRef(new PauseState(_data)), false);
    }
}

void GameState::Update() {
    _entityFactory->updateCharacters();
    updateScore();
    updateLives();
}

void GameState::Draw() {
    _data->window.clear(Color::BLACK);
    _data->window.draw(_background);

    _entityFactory->drawAll(_data->window);

    _data->window.draw(_scoreText);
    _data->window.draw(_livesText);
    _data->window.display();
}

void GameState::initView() { EntityDataMap map = _world->GetFullMap(); }

void GameState::updateScore() { _scoreText.setString("Score: " + std::to_string(_world->GetOutputData().score)); }

void GameState::updateLives() { _livesText.setString("Lives: " + std::to_string(_world->GetOutputData().lives)); }
} // namespace View