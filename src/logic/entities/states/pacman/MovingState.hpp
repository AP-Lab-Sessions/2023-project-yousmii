#ifndef MOVINGSTATE_HPP
#define MOVINGSTATE_HPP

#include "../PacmanState.hpp"
#include "../../Pacman.hpp"

namespace Logic {

class MovingState : public PacmanState {
public:
    explicit MovingState(PacmanDataPtr pacmanData);

    /// @brief Initialize moving state
    void init() override;

    /// @brief moving??? in this state??? Sure, go ahead
    void move() override;
    /// @brief die in the moving state, goes to paused state
    void die() override;
    /// @brief slip in the moving state, goes to paused state
    void slip() override;

    /// @brief update the moving state, moves pacman and updates the next move time
    void update() override;

private:
    PacmanDataPtr _pacmanData;
    float _nextMove = 1.0f / 3.0f ; // 3 moves per second
};

} // Logic

#endif //MOVINGSTATE_HPP
