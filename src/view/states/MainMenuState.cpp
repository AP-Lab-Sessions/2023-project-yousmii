#include "MainMenuState.hpp"
#include "../../DEFINITIONS.hpp"
#include "GameState.hpp"
#include "singletons/Randomizer.hpp"

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
    _spacetostart.setString("Press SPACE to start a random level");
    _spacetostart.setCharacterSize(30);
    _spacetostart.setFillColor(Color::WHITE);
    _spacetostart.setPosition(_centerwindow.x - _spacetostart.getGlobalBounds().width / 2,
                              _centerwindow.y - _spacetostart.getGlobalBounds().height / 2 + 125);
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
    initLevel1Start();
    initLevel2Start();
}

void MainMenuState::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        int randomLevel = Singletons::RNG::getInstance().getRandomInt(1,2);
        _data->machine.AddState(StateRef(new GameState(_data, randomLevel)), true);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
        _data->machine.AddState(StateRef(new GameState(_data, 1)), true);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
        _data->machine.AddState(StateRef(new GameState(_data, 2)), true);
    }
}

void MainMenuState::Update() {}

void MainMenuState::Draw() {
    _data->window.clear(Color::BLACK);

    _data->window.draw(_icon);
    _data->window.draw(_title);
    _data->window.draw(_spacetostart);
    _data->window.draw(_level1Start);
    _data->window.draw(_level2Start);

    _data->window.display();
}

void MainMenuState::initLevel1Start() {
    _level1Start.setFont(_data->assets.GetFont(DSFONT));
    _level1Start.setString("Press 1 to start level 1");
    _level1Start.setCharacterSize(25);
    _level1Start.setFillColor(Color::CYAN);
    _level1Start.setPosition(_centerwindow.x - _level1Start.getGlobalBounds().width / 2,
                              _centerwindow.y - _level1Start.getGlobalBounds().height / 2 + 160);
}

void MainMenuState::initLevel2Start() {
    _level2Start.setFont(_data->assets.GetFont(DSFONT));
    _level2Start.setString("Press 2 to start level 2");
    _level2Start.setCharacterSize(25);
    _level2Start.setFillColor(Color::CYAN);
    _level2Start.setPosition(_centerwindow.x - _level2Start.getGlobalBounds().width / 2,
                              _centerwindow.y - _level2Start.getGlobalBounds().height / 2 + 190);
}

} // namespace View