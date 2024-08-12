#ifndef PACMANSTATE_HPP
#define PACMANSTATE_HPP

#include <memory>

namespace Logic {

struct PacmanData {
    int x, y;
    int lives, score;
    bool isPowerUp;
    bool isAlive;
};

typedef std::shared_ptr<PacmanData> PacmanDataPtr;

class PacmanState {
public:
    PacmanState(PacmanDataPtr pacmanData) {};
    virtual ~PacmanState() = default;

    virtual void move() = 0;
    virtual void die() = 0;
    virtual void powerUp() = 0;

protected:
     PacmanDataPtr _pacmanData;
};

} // Logic

#endif //PACMANSTATE_HPP
