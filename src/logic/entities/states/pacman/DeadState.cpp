#include "DeadState.hpp"

#include "MovingState.hpp"

namespace Logic {
DeadState::DeadState(PacmanDataPtr pacmanData) : _pacmanData(std::move(pacmanData)) {
    _deathTime = 1.0f;
}

void DeadState::die() {
    // Do nothing
}

void DeadState::init() {
    _pacmanData->isAlive = false;
    _pacmanData->isMoving = false;

    _pacmanData->x = _pacmanData->spawnX;
    _pacmanData->y = _pacmanData->spawnY;
}

void DeadState::move() {
    // Do nothing
}

void DeadState::powerDown() {
    // Do nothing
}

void DeadState::powerUp() {
    // Do nothing
}

void DeadState::slip() {
    // Do nothing
}
void DeadState::changeDirection(Direction direction) {
    // Do nothing
}

void DeadState::update() {
    _deathTime -= 1.0f / 30.0f;
    if (_deathTime <= 0.0f) {
        _pacmanData->stateManager->addState(std::make_unique<MovingState>(_pacmanData));
    }
}
} // Logic