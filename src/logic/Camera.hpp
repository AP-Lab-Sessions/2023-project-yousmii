#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../DEFINITIONS.hpp"
#include "level/Level.hpp"

#include <memory>
#include <mutex>

namespace Logic {

/// @brief The camera class is responsible for Observing the level and returning the necessary data to the renderer.
class Camera {
public:
    Camera(LevelPtr level);
    ~Camera() = default;

    /// @brief Get the full tilemap of the level. Useful for the initial rendering of the level.
    EntityDataMap getFullMap();
    /// @brief Get the updates of the level. Does not return the full map.
    // void getUpdates();
    /// @brief Get the output data of the level. Gives current score and lives.
    OutputData getOutputData();

private:
    LevelPtr _level;
};

typedef std::unique_ptr<Camera> CameraPtr;
} // Logic

#endif //CAMERA_HPP
