#include "GameState.hpp"

namespace View {
GameState::GameState(GameDataRef data) : _data(data) {}

void GameState::init() {
    _background.setSize(sf::Vector2f(600, 600));
    _background.setPosition((_data->window.getSize().x - _background.getSize().x) / 2,
                            (_data->window.getSize().y - _background.getSize().y) / 2);
    _background.setFillColor(sf::Color::Black);
}

void GameState::HandleInput() {
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _data->window.close();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        // _data->machine.AddState(StateRef(new PauseMenuState(_data)), false);
    }
}

void GameState::Update() {}

void GameState::Draw() {
    _data->window.clear(Color::DARK_BLUE);
    _data->window.draw(_background);
    _data->window.display();
}

} // namespace View