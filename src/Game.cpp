#include "Game.hpp"

#include "STATE_LIST.hpp"
#include "DEFINITIONS.hpp"

namespace View {
Game::Game() {
    _data->assets.LoadFont("Monocraft", "assets/fonts/Monocraft.ttf");
    _data->assets.LoadFont("Pluh", "assets/fonts/pluh.ttf");

    _data->assets.LoadTexture("Sprites", "assets/textures/Sprites.png");
    _data->assets.LoadImage("Icon", "assets/textures/Icon.png");
    _data->assets.LoadTexture("Icon", "assets/textures/Icon.png");

    _data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE, sf::Style::Close | sf::Style::Titlebar);
    _data->window.setFramerateLimit(FRAMERATE_LIMIT);
    _data->window.setIcon( _data->assets.GetImage("Icon").getSize().x,  _data->assets.GetImage("Icon").getSize().y,  _data->assets.GetImage("Icon").getPixelsPtr());

    StateRef splash_state(new MainMenuState(_data));
    _data->machine.AddState(std::move(splash_state));

    _data->stopwatch.Start();
    Run();
}

void Game::Run() {
    const double dt = 0.01;
    double accumulator = 0.0;

    while (_data->window.isOpen()) {
        _data->machine.ProcessStateChanges();
        _data->stopwatch.Tick();

        accumulator += _data->stopwatch.GetFrameTime();

        while (accumulator >= dt) {
            _data->machine.GetActiveState()->HandleInput();
            _data->machine.GetActiveState()->Update(dt);

            accumulator -= dt;
        }
        double interpolation = accumulator / dt;
        _data->machine.GetActiveState()->Draw(interpolation);
    }
}

} // namespace View