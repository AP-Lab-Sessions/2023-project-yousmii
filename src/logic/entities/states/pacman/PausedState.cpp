#include "PausedState.hpp"

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
    _pauseTime = 1.0f; // 1 second pause
}

void PausedState::slip() {
    // Doesn't slip
}

void PausedState::update() {
    _pauseTime -= TICK_RATE; // 30 frames per second
    if (_pauseTime <= 0.0f) {
        _pacmanData->stateManager->addState(std::make_unique<MovingState>(_pacmanData));
    }
}
void PausedState::changeDirection(Direction direction) {
    _pacmanData->direction = direction;
}

} // Logic