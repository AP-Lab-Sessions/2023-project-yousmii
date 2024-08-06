#include "Game.hpp"

#include "DEFINITIONS.hpp"
#include "STATE_LIST.hpp"

namespace View {
Game::Game() {
    // Asset loading
    _data->assets.LoadFont(MONOCRAFT, "assets/fonts/Monocraft.ttf");
    _data->assets.LoadFont(DSFONT, "assets/fonts/pluh.ttf");

    _data->assets.LoadTexture("Icon", "assets/textures/Icon.png");
    _data->assets.LoadImage("Icon", "assets/textures/Icon.png");

    // Window creation
    _data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE,
                         sf::Style::Close | sf::Style::Titlebar);
    _data->window.setFramerateLimit(FRAMERATE_LIMIT);
    _data->window.setIcon(_data->assets.GetImage("Icon").getSize().x, _data->assets.GetImage("Icon").getSize().y,
                          _data->assets.GetImage("Icon").getPixelsPtr());

    // State creation
    StateRef menu_state(new MainMenuState(_data));
    _data->machine.AddState(std::move(menu_state));

    _data->stopwatch.Start();
    Run();
}

void Game::Run() {

    while (_data->window.isOpen()) {
        _data->machine.ProcessStateChanges();
        _data->stopwatch.Tick();
        _data->machine.GetActiveState()->HandleInput();
        _data->machine.GetActiveState()->Update();
        _data->machine.GetActiveState()->Draw();
    }
}

} // namespace View