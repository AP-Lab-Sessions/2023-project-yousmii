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

/// @brief The camera class is responsible for viewing the level and returning the necessary data to the renderer and entities involved in the game.
class Camera {
public:
    explicit Camera(std::weak_ptr<Level> level);
    ~Camera() = default;

    /// @brief Get the full tilemap of the level. Used for the initial rendering of the level.
    EntityDataMap getFullMap();

    /// @brief Get the output data of the level. Gives current score and lives.
    OutputData getOutputData();

private:
    std::weak_ptr<Level> _level;
};

typedef std::unique_ptr<Camera> CameraPtr;
} // Logic

#endif //CAMERA_HPP
