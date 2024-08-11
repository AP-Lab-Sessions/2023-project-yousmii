#include "PauseState.hpp"

#include "../../DEFINITIONS.hpp"
#include "MainMenuState.hpp"

namespace View {

PauseState::PauseState(GameDataPtr data) : _data(data) {}

void PauseState::initPauseText() {
    _pauseText.setString("PAUSED");
    _pauseText.setCharacterSize(128);
    _pauseText.setFont(_data->assets.GetFont(MONOCRAFT));
    _pauseText.setFillColor(Color::WHITE);
    _pauseText.setOrigin(_pauseText.getGlobalBounds().width / 2, _pauseText.getGlobalBounds().height / 2);
    _pauseText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2 - 120);
}

void PauseState::initResumeText() {
    _resumeText.setString("Press Escape again to resume");
    _resumeText.setCharacterSize(30);
    _resumeText.setFont(_data->assets.GetFont(DSFONT));
    _resumeText.setFillColor(Color::WHITE);
    _resumeText.setOrigin(_resumeText.getGlobalBounds().width / 2, _resumeText.getGlobalBounds().height / 2);
    _resumeText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
}

void PauseState::initExitText() {
    _exitText.setString("Press E to exit");
    _exitText.setCharacterSize(30);
    _exitText.setFont(_data->assets.GetFont(DSFONT));
    _exitText.setFillColor(Color::WHITE);
    _exitText.setOrigin(_exitText.getGlobalBounds().width / 2, _exitText.getGlobalBounds().height / 2);
    _exitText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2 + 50);
}

void PauseState::initResumeButton() {}

void PauseState::initExitButton() {}

void PauseState::init() {
    std::cout << "PauseState initialised" << std::endl;
    initPauseText();
    initResumeText();
    initExitText();
}

void PauseState::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        _data->machine.RemoveState();
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        _data->machine.RemoveState();
        _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
    }
}

void PauseState::Update() {}

void PauseState::Draw() {
    _data->window.clear(Color::BLUE);
    _data->window.draw(_pauseText);
    _data->window.draw(_resumeText);
    _data->window.draw(_exitText);
    _data->window.display();
}
} // namespace View