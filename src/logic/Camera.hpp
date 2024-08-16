#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../DEFINITIONS.hpp"
#include "level/Level.hpp"

#include <memory>

namespace Logic {

struct TileInfo {
    int row, col;
    EntityType type;
};

/// @brief The camera class is responsible for Observing the level and returning the necessary data to the renderer and entities involved in the game.
class Camera { // imma make this a singleton observer
public:
    Camera(LevelPtr level);
    ~Camera() = default;

    /// @brief Get the full tilemap of the level. Useful for the initial rendering of the level.
    EntityDataMap getFullMap();
    /// @brief Get the updates of the level. Does not return the full map.
    // void getUpdates();
    /// @brief Get the output data of the level. Gives current score and lives.
    OutputData getOutputData();

    TileInfo getTileInfo(int row, int col);
    void changeLevel(LevelPtr level);

private:
    LevelPtr _level;
    // EventQueuePtr _eventQueue;
};

typedef std::unique_ptr<Camera> CameraPtr;
} // Logic

#endif //CAMERA_HPP
