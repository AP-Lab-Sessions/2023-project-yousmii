#ifndef PACMAN_HPP
#define PACMAN_HPP
#include "../../DEFINITIONS.hpp"
#include "Entity.hpp"
#include "states/PacmanStateManager.hpp"

namespace Logic{

struct PacmanData {
    int x, y;

    bool isAlive;
    bool isMoving;

    Direction direction;
    PacmanStateManagerPtr stateManager;
};

typedef std::shared_ptr<PacmanData> PacmanDataPtr;

class Pacman : public Entity {
public:
    Pacman(int x, int y);
    ~Pacman() override = default;

    void update();
    void setDirection(Direction direction);
    Direction getDirection() const { return _pacmanData->direction; }
    bool isMoving() const { return _pacmanData->isMoving; }

private:
    void updateData();
    PacmanDataPtr _pacmanData;
};

} // Logic

#endif //PACMAN_HPP
