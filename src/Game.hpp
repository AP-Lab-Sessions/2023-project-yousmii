#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "AssetManager.hpp"
#include "DEFINITIONS.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"
#include "Stopwatch.hpp"

namespace Rep {

struct GameData {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    Logic::Stopwatch stopwatch = Logic::Stopwatch::GetInstance();
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game {
public:
    Game();

private:
    GameDataRef _data = std::make_shared<GameData>();
    void Run();
};
} // namespace Rep

#endif // GAME_H
