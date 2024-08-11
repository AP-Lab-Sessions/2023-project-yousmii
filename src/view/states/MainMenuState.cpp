#include "MainMenuState.hpp"
#include "../../DEFINITIONS.hpp"
#include "GameState.hpp"

#include <iostream>

namespace View {
MainMenuState::MainMenuState(GameDataPtr data) : _data(data) {}

void MainMenuState::initTitle() {
    _title.setFont(_data->assets.GetFont(MONOCRAFT));
    _title.setString("CPPacman");
    _title.setCharacterSize(72);
    _title.setFillColor(Color::CYAN);
    _title.setPosition(_centerwindow.x - _title.getGlobalBounds().width / 2,
                       _centerwindow.y - _title.getGlobalBounds().height / 2 - 175);
}

void MainMenuState::initSpaceToStart() {
    _spacetostart.setFont(_data->assets.GetFont(DSFONT));
    _spacetostart.setString("Press SPACE to start");
    _spacetostart.setCharacterSize(25);
    _spacetostart.setFillColor(Color::WHITE);
    _spacetostart.setPosition(_centerwindow.x - _spacetostart.getGlobalBounds().width / 2,
                              _centerwindow.y - _spacetostart.getGlobalBounds().height / 2 + 130);
}

void MainMenuState::initIcon() {
    _icon.setTexture(_data->assets.GetTexture("Icon"));
    _icon.setScale(5,5);
    _icon.setPosition(_centerwindow.x - _icon.getGlobalBounds().width / 2,
                      _centerwindow.y - _icon.getGlobalBounds().height / 2);
}

void MainMenuState::init() {
    std::cout << "MainMenuState initialised" << std::endl;
    _centerwindow = sf::Vector2f(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
    initIcon();
    initTitle();
    initSpaceToStart();
}

void MainMenuState::HandleInput() {
    sf::Event event;
    // TODO: add 1 and 2 to change the level :)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        _data->machine.AddState(StateRef(new GameState(_data)), true);
    }
}

void MainMenuState::Update() {}

void MainMenuState::Draw() {
    _data->window.clear(Color::BLACK);
    _data->window.draw(_icon);
    _data->window.draw(_title);
    _data->window.draw(_spacetostart);
    _data->window.display();
}

} // namespace View