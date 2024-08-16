#include "Pacman.hpp"

namespace Logic {
Pacman::Pacman(int x, int y) : Entity(x, y) {
    _type = EntityType::PACMAN;
    _pacmanData = std::make_shared<PacmanData>();
    _stateManager = std::make_unique<PacmanStateManager>(_pacmanData);
}

void Pacman::update() {
    _stateManager->processStateChanges();
    _stateManager->getActiveState()->update();
    updateData();
}

void Pacman::changeDirection(Direction direction) {
    _stateManager->getActiveState()->changeDirection(direction);
}

void Pacman::updateData() {
    setPosition(_pacmanData->x, _pacmanData->y);
}


} // namespace Logic