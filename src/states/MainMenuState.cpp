#include "MainMenuState.hpp"

#include <iostream>

namespace View {
MainMenuState::MainMenuState(GameDataRef data) : _data(data) {}

void MainMenuState::init() {
    std::cout << "MainMenuState initialised" << std::endl;

    _icon.setTexture(_data->assets.GetTexture("Icon"));

    sf::Vector2f center_icon = sf::Vector2f(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
    _icon.setPosition(center_icon.x - _icon.getGlobalBounds().width / 2, center_icon.y - _icon.getGlobalBounds().height / 2);
}

void MainMenuState::HandleInput() {
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
           _data->window.close();
        }
    }
}

void MainMenuState::Update(double dt) {

}

void MainMenuState::Draw(double dt) {
    _data->window.clear(Color::DARK_BLUE);
    _data->window.draw(_icon);
    _data->window.display();
}


} // namespace View