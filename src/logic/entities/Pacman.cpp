#include "Pacman.hpp"

#include "states/pacman/PausedState.hpp"

#include <iostream>

namespace Logic {
Pacman::Pacman(int x, int y) : Entity(x, y) {
    std::cout << "Pacman constructor" << std::endl;
    _type = EntityType::PACMAN;
    _pacmanData = std::make_shared<PacmanData>();
    _pacmanData->x = x;
    _pacmanData->y = y;

    _pacmanData->isAlive = true;
    _pacmanData->stateManager = std::make_unique<PacmanStateManager>();

    _pacmanData->stateManager->addState(std::make_unique<PausedState>(_pacmanData));
}

void Pacman::update() {
    _pacmanData->stateManager->processStateChanges();
    _pacmanData->stateManager->getActiveState()->update();
}

void Pacman::setDirection(Direction direction) { _pacmanData->direction = direction; }

void Pacman::updateData() {

}


} // namespace Logic