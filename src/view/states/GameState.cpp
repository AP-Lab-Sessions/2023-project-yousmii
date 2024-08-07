#include "GameState.hpp"

#include "PauseState.hpp"
#include <utility>

namespace View {
GameState::GameState(GameDataPtr data) : _data(std::move(data)) {
    EntityFactoryPtr entityFactory(
        new EntityFactory(_data->assets.GetTexture("Sprites"))); // remember that putting this in init
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
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _data->window.close();
        }
    }
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