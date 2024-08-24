#ifndef PACMANSTATE_HPP
#define PACMANSTATE_HPP

#include "../../../DEFINITIONS.hpp"

#include <memory>

namespace Logic {

class PacmanState {
public:
    /// @brief Pacman state constructor
    PacmanState() = default;
    ~PacmanState() = default;

    /// @brief Initialize pacman state
    virtual void init() = 0;
    /// @brief Update pacman according to its state
    virtual void update() = 0;

    /// @brief Move pacman
    virtual void move() = 0;
    /// @brief Die >:(
    virtual void die() = 0;
    /// @brief Woopsie daisy, slip on a banana peel, that banana peel totally isnt a frame of pacman dying or anything
    virtual void slip() = 0;
};

typedef std::unique_ptr<PacmanState> PacmanStatePtr;

} // namespace Logic

#endif // PACMANSTATE_HPP
