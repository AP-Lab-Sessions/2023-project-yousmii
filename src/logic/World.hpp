#ifndef WORLD_HPP
#define WORLD_HPP
#include "../DEFINITIONS.hpp"
#include "../singletons/Stopwatch.hpp"
#include "Camera.hpp"
#include "Simulator.hpp"
#include "level/Level.hpp"

#include <memory>

namespace Logic {

/// @brief WorldData is a struct that holds the data that could be handy at some point.
struct WorldData {
    unsigned int width;
    unsigned int height;
    Singletons::Stopwatch stopwatch = Singletons::Stopwatch::GetInstance();
};

/// @brief WorldDataPtr is a shared pointer to WorldData.
typedef std::shared_ptr<WorldData> WorldDataPtr;

class World {
public:
    /// @brief Manager class for the game world.
    /// @param levelNumber The number of the level to load.
    explicit World(int levelNumber);
    ~World() = default;

    /// @brief Updates the world. Calls the simulator.
    void Update();

    /// @brief Returns the full map of the world. Calls the camera for this (to get a 'picture').
    /// @return EntityDataMap The full map of the world. Has all the entities and their positions.
    EntityDataMap GetFullMap();

    /// @brief Returns events that happened in the world.
    /// @return Stack of events that happened in the world.
    Events GetUpdates();

    /// @brief Returns the output data of the world.
    /// @return Holds the score, lives and if the game is over.
    OutputData GetOutputData();

    /// @brief Set the direction of the player.
    void SetPlayerDirection(Direction direction);

    /// @brief Tells if Pacman is moving, that way we can know if we should update the visual direction.
    [[nodiscard]] bool pacmanIsMoving() const;

private:
    SimulatorPtr _simulator;
    CameraPtr _camera;
};

} // Logic

#endif //WORLD_HPP
