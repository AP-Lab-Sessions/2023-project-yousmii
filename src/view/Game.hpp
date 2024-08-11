#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"
#include "../singletons/Stopwatch.hpp"

namespace View {

struct GameData {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    Singletons::Stopwatch stopwatch = Singletons::Stopwatch::GetInstance();
};

typedef std::shared_ptr<GameData> GameDataPtr;

class Game {
public:
    Game();

private:
    GameDataPtr _data = std::make_shared<GameData>();
    void Run();
};
} // namespace View

#endif // GAME_H
