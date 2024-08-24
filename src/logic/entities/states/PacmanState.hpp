#ifndef PACMANSTATE_HPP
#define PACMANSTATE_HPP

#include "../../../DEFINITIONS.hpp"

#include <memory>

namespace Logic {

class PacmanState {
public:
    PacmanState() = default;
    virtual ~PacmanState() = default;

    virtual void init() = 0;
    virtual void update() = 0;

    virtual void move() = 0;
    virtual void die() = 0;
    virtual void slip() = 0; // Banana moment :D
    virtual void changeDirection(Direction direction) = 0;
};

typedef std::unique_ptr<PacmanState> PacmanStatePtr;

} // namespace Logic

#endif // PACMANSTATE_HPP
