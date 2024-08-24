#ifndef MOVINGSTATE_HPP
#define MOVINGSTATE_HPP

#include "../PacmanState.hpp"
#include "../../Pacman.hpp"

namespace Logic {

class MovingState : public PacmanState {
public:
    MovingState(PacmanDataPtr pacmanData);
    ~MovingState() override = default;

    void init() override;
    void move() override;
    void die() override;
    void slip() override;
    void changeDirection(Direction direction) override;

    void update() override;

private:
    PacmanDataPtr _pacmanData;
    float _nextMove = 0.3f;
};

} // Logic

#endif //MOVINGSTATE_HPP
