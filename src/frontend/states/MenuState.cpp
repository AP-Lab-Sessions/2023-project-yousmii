#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<Game> game) {
    this->game = game;

    if (!font.loadFromFile("lib/fonts/Monocraft.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    this->title.setFont(this->font);
    this->title.setString("CPPacman");
    this->title.setCharacterSize(100);
    this->title.setFillColor(sf::Color::White);
    this->title.setOutlineColor(sf::Color::Blue);
    this->title.setOutlineThickness(5);
    this->title.setOrigin(this->title.getLocalBounds().width / 2, this->title.getLocalBounds().height / 2);
    this->title.setPosition(400, 300);
}

MenuState::onEnter() { std::cout << "Entered MenuState" << std::endl; }

MenuState::onExit() { std::cout << "Exited MenuState" << std::endl; }

MenuState::update(float dt) {}

MenuState::render() const {
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(title);
    this->game->window.display();
}