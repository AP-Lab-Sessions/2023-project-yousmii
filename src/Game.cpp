#include "Game.hpp"


namespace View {
Game::Game() {
    _data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE, sf::Style::Close | sf::Style::Titlebar);
    _data->window.setFramerateLimit(FRAMERATE_LIMIT);

    _data->assets.LoadFont("Monocraft", "assets/fonts/Monocraft.ttf");
    _data->assets.LoadTexture("Sprites", "assets/textures/Sprites.png");

    _data->stopwatch.Start();
    // Run();
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