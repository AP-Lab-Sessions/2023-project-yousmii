#include "Game.hpp"

namespace Rep {
Game::Game() {
    _data->window.create(sf::VideoMode(800, 600), "CPPacman", sf::Style::Close | sf::Style::Titlebar);
    _data->stopwatch.Start();
    Run();
}

void Game::Run() {
    while (_data->window.isOpen()) {
    }

}

}