#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"
#include "../singletons/Stopwatch.hpp"

namespace View {

/// @brief Structure to hold the game data, passed to each state.
/// Holds the state machine, window, asset manager, input manager, and stopwatch
struct GameData {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    Singletons::Stopwatch stopwatch = Singletons::Stopwatch::GetInstance();
};

typedef std::shared_ptr<GameData> GameDataPtr;

/// @brief The main game class that runs the game loop
class Game {
public:
    /// @brief Constructor, adds the first state to the state machine and runs the game
    Game();

private:
    GameDataPtr _data = std::make_shared<GameData>();
    void Run();
};
} // namespace View

#endif // GAME_H
