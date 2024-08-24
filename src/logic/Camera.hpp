#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../DEFINITIONS.hpp"
#include "level/Level.hpp"

#include <memory>

namespace Logic {

struct OutputData { // Easy access to the output data, cannot alter the original data
    int score;
    int lives;
    bool isCompleted = false;
    bool won = false;
};

struct TileInfo {
    int row, col;
    EntityType type;
};

/// @brief The camera class is needed for viewing the entire level and getting the output data.
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
