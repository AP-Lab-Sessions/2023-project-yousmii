

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include "Events.hpp"
#include "level/Level.hpp"

namespace Logic {

/// @brief The Simulator class is responsible for simulating the game, it will be responsible for updating the World and
/// the Entities.
class Simulator {
public:
    /// @brief Constructor of the Simulator
    /// @param level The level to simulate.
    explicit Simulator(LevelPtr level);
    ~Simulator();

    /// @brief Updates the level as a whole and calls the update function of the entities.
    void update();

    /// @brief Returns the level of the simulator. Only used for the Camera.
    std::weak_ptr<Level> getLevel();

    /// @brief Returns the events of the simulator.
    /// @return The events of the simulator.
    Events getEvents();

private:
    /// @brief Simulates the Pacman. Moves the Pacman, check if movement is possible and if it is, moves Pacman.
    void simulatePacman();

    /// @brief Moves Pacman to its new positon and applies all changes.
    void movePacman();

    /// @brief Simulates the ghosts.
    // void simulateGhosts();

    /// @brief Simulates the level. Calls the simulate function of all entities.
    void simulateLevel();

    /// @brief Called if the Pacman collides with a coin and updates the score.
    void collectCoin(int x, int y);

    // void collectPowerUp();
    // void eatGhost();
    // void die();
    // void win();

    void updateScore();

    /// @brief Resets the characters to their starting positions. Used when the player dies.
    void resetCharacters();

    /// @brief Resets a single character to its starting position.
    void resetCharacter(std::weak_ptr<Entity>& entity);

    LevelPtr _level;
    bool _gameOver = false;
    bool _win = false;

    float nextScoreUpdate = 1.0f;
    Events _events;
};

typedef std::unique_ptr<Simulator> SimulatorPtr;
} // namespace Logic

#endif // SIMULATOR_HPP
