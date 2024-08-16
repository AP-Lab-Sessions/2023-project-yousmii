#ifndef MOVINGSTATE_HPP
#define MOVINGSTATE_HPP

#include "../PacmanState.hpp"
namespace Logic {

class MovingState : public PacmanState {
public:
    MovingState(PacmanDataPtr pacmanData) : PacmanState(std::move(pacmanData)) {}
    ~MovingState() override = default;

    void init() override;
    void move() override;
    void die() override;
    void powerUp() override;
    void powerDown() override;
    void slip() override;
    void changeDirection(Direction direction) override;
};

} // Logic

#endif //MOVINGSTATE_HPP
