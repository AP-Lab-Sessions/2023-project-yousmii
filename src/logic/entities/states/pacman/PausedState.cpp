#include "PausedState.hpp"

#include "DeadState.hpp"
#include "MovingState.hpp"

namespace Logic {
PausedState::PausedState(PacmanDataPtr pacmanData) : _pacmanData(std::move (pacmanData)) {
    _pauseTime = 1.0f; // 1 second pause
};

void PausedState::init() {
    _pacmanData->isMoving = false;
}

void PausedState::move() {
    // Doesn't move
}

void PausedState::die() {
    PacmanStatePtr deadState = std::make_unique<DeadState>(_pacmanData);
    _pacmanData->stateManager->addState(std::move(deadState));
}

void PausedState::powerUp() {
    // Doesn't power up
}

void PausedState::powerDown() {
    // Doesn't power down
}

void PausedState::slip() {
    // Doesn't slip
}

void PausedState::update() {
    _pauseTime -= 1.0f / 30.0f; // 30 frames per second
    if (_pauseTime <= 0.0f) {
        _pacmanData->stateManager->addState(std::make_unique<MovingState>(_pacmanData));
    }
}
void PausedState::changeDirection(Direction direction) {
    _pacmanData->direction = direction;
}

} // Logic