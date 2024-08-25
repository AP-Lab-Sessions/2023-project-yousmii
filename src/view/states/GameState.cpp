#include "GameState.hpp"

#include "GameOverState.hpp"
#include "PauseState.hpp"

#include <utility>

namespace View {
GameState::GameState(GameDataPtr data, int level) : _data(std::move(data)), _level(level) {
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2)) { // Cheat code for presenting the win screen
        _data->machine.AddState(StateRef(new GameOverState(_data, 69420, true, _level)), true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F3)) { // Cheat code for presenting the lose screen
        _data->machine.AddState(StateRef(new GameOverState(_data, 0, false, _level)), true);
    }

    if (_world->pacmanIsMoving()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            _world->SetPlayerDirection(Direction::UP);
            _entityFactory->setCharacterDirection(CharacterName::Pacman, Direction::UP);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            _world->SetPlayerDirection(Direction::DOWN);
            _entityFactory->setCharacterDirection(CharacterName::Pacman, Direction::DOWN);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            _world->SetPlayerDirection(Direction::LEFT);
            _entityFactory->setCharacterDirection(CharacterName::Pacman, Direction::LEFT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            _world->SetPlayerDirection(Direction::RIGHT);
            _entityFactory->setCharacterDirection(CharacterName::Pacman, Direction::RIGHT);
        }
    }
}

void GameState::Update() {
    if (!_world->GetOutputData().isCompleted) {
        _world->Update();
        HandleEvents(_world->GetUpdates());

        _entityFactory->updateCharacters();
        updateScore();
        updateLives();
    } else {
        Logic::OutputData outputData = _world->GetOutputData();
        _data->machine.AddState(StateRef(new GameOverState(_data, outputData.score, outputData.won, _level)), true);
    }
}

void GameState::HandleEvents(Events events) {
    while (!events.empty()) {
        Event event = events.front();
        switch (event.type) {
        case EventType::coinEaten:
            _entityFactory->removeCollectable(event.x, event.y);
            break;
        case EventType::pacmanPositionChange:
            _entityFactory->moveCharacter(CharacterName::Pacman, event.x, event.y);
            break;
        default:
            break;
        }
        events.pop();
    }
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