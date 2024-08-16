#ifndef PACMANSTATE_HPP
#define PACMANSTATE_HPP

#include "../../../DEFINITIONS.hpp"

#include <memory>

namespace Logic {

struct PacmanData {
    int x, y;

    bool isPowerUp;
    bool isAlive;
    bool isMoving;

    Direction direction;
};

typedef std::shared_ptr<PacmanData> PacmanDataPtr;

class PacmanState {
public:
    explicit PacmanState(PacmanDataPtr pacmanData): _pacmanData(std::move(pacmanData)){};
    virtual ~PacmanState() = default;

    virtual void init() = 0;
    virtual void update() = 0;

    virtual void move() = 0;
    virtual void die() = 0;
    virtual void powerUp() = 0;
    virtual void powerDown() = 0;
    virtual void slip() = 0; // Banana moment :D
    virtual void changeDirection(Direction direction) = 0;

    PacmanDataPtr getPacmanData() { return _pacmanData; }

protected:
    PacmanDataPtr _pacmanData;
};

} // namespace Logic

#endif // PACMANSTATE_HPP
