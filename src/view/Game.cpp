#include "Game.hpp"

#include "../DEFINITIONS.hpp"
#include "STATE_LIST.hpp"

namespace View {
Game::Game() {
    // Asset loading
    _data->assets.LoadFont(MONOCRAFT, "assets/fonts/Monocraft.ttf");
    _data->assets.LoadFont(DSFONT, "assets/fonts/pluh.ttf");
    _data->assets.LoadTexture("Sprites", "assets/textures/Sprites.png");
    _data->assets.LoadTexture("Icon", "assets/textures/Icon.png");
    _data->assets.LoadImage("Icon", "assets/textures/Icon.png");

    // Window creation
    _data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE,
                         sf::Style::Close | sf::Style::Titlebar);
    _data->window.setFramerateLimit(FRAMERATE_LIMIT); // You can change this in SETTINGS.hpp :D
    _data->window.setIcon(_data->assets.GetImage("Icon").getSize().x, _data->assets.GetImage("Icon").getSize().y,
                          _data->assets.GetImage("Icon").getPixelsPtr());

    // State creation
    StateRef menu_state(new MainMenuState(_data));
    _data->machine.AddState(std::move(menu_state));

    _data->stopwatch.Start();
    Run();
}

void Game::Run() {
    double accumulator = 0.0; // Time accumulator, used for fixed timestep logic
    const float dt = TICK_RATE; // currently 30 update frames per second, tick rate of the game, you can change this in DEFINITIONS.hpp

    while (_data->window.isOpen()) {
        // Apply changes
        _data->machine.ProcessStateChanges();
        // Check for window close
        _data->input.checkClose(_data->window);

        // Timestep
        _data->stopwatch.Tick();
        float frameTime = _data->stopwatch.GetFrameTime();
        accumulator += frameTime;

        // Update the game logic
        while (accumulator >= dt) {
            _data->machine.GetActiveState()->HandleInput();
            _data->machine.GetActiveState()->Update();
            accumulator -= dt; // Subtract the time that has been processed, useful in case of lag
        }
        // Draw the game
        _data->machine.GetActiveState()->Draw();
    }
}

} // namespace View