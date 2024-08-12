#include "GameState.hpp"

#include "PauseState.hpp"
#include <utility>

namespace View {
GameState::GameState(GameDataPtr data, unsigned int level) : _data(std::move(data)), _level(level) {
    EntityFactoryPtr entityFactory(
        new EntityFactory(_data->assets.GetTexture("Sprites")));
    _entityFactory = std::move(entityFactory);
}

void GameState::init() {
    std::cout << "GameState initialised" << std::endl;
    _background.setSize(sf::Vector2f(600, 600));
    _background.setPosition((_data->window.getSize().x - _background.getSize().x) / 2,
                            (_data->window.getSize().y - _background.getSize().y) / 2);
    _background.setFillColor(sf::Color::Black);
}

void GameState::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        _data->machine.AddState(StateRef(new PauseState(_data)), false);
    }
}

void GameState::Update() {}

void GameState::Draw() {
    _data->window.clear(Color::BLUE);
    _data->window.draw(_background);
    _data->window.display();
}

} // namespace View