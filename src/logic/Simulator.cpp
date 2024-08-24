#include "Simulator.hpp"

#include <iostream>

namespace Logic {
Simulator::Simulator(LevelPtr level) : _level(std::move(level)) { std::cout << "Simulator created" << std::endl; }

Simulator::~Simulator() { std::cout << "Simulator destroyed" << std::endl; }
void Simulator::update() { simulateLevel(); }

std::weak_ptr<Level> Simulator::getLevel() { return std::weak_ptr<Level>(_level); }

Events Simulator::getEvents() { return _events; }

void Simulator::simulateLevel() {
    updateScore();
    _events = Events(); // Clear events
    simulatePacman();
}

void Simulator::collectCoin(int x, int y) {
    _level->getScore()->addScore(10);
    _level->eatCoin();
    _events.push(Event(EventType::coinEaten, x, y));
}

void Simulator::updateScore() {
    if (nextScoreUpdate <= 0.0f) {
        _level->getScore()->subtractScore(1);
        nextScoreUpdate = 1.0f;
    } else {
        nextScoreUpdate -= TICK_RATE;
    }
}

void Simulator::resetCharacters() {
    std::weak_ptr<Entity> entity;
    // Reset Pacman
    entity = _level->getPacman();
    resetCharacter(entity);
    _events.push(Event(EventType::pacmanPositionChange, entity.lock()->getPosition().first, entity.lock()->getPosition().second));

    // Reset ghosts
    entity = _level->getGhost(CharacterName::Blinky);
    resetCharacter(entity);
    _events.push(Event(EventType::blinkyPositionChange, entity.lock()->getPosition().first, entity.lock()->getPosition().second));

    entity = _level->getGhost(CharacterName::Pinky);
    resetCharacter(entity);
    _events.push(Event(EventType::pinkyPositionChange, entity.lock()->getPosition().first, entity.lock()->getPosition().second));

    entity = _level->getGhost(CharacterName::Inky);
    resetCharacter(entity);
    _events.push(Event(EventType::inkyPositionChange, entity.lock()->getPosition().first, entity.lock()->getPosition().second));

    entity = _level->getGhost(CharacterName::Clyde);
    resetCharacter(entity);
    _events.push(Event(EventType::clydePositionChange, entity.lock()->getPosition().first, entity.lock()->getPosition().second));
}

void Simulator::resetCharacter(std::weak_ptr<Entity>& entity) {
    entity.lock()->reset();
    _level->moveTileEntity(entity.lock()->getCharacterName(), entity.lock()->getPosition().first, entity.lock()->getPosition().second, true);
}

void Simulator::simulatePacman() {
    std::weak_ptr<Pacman> pacman = _level->getPacman();
    pacman.lock()->update();

    if (pacman.lock()->isMoving()) {
        std::pair<int, int> newCoords = pacman.lock()->getNewPosition();
        if (pacman.lock()->getPosition() == newCoords) {
            return;
        }
        std::weak_ptr<Tile> newTile = _level->getTile(newCoords.first, newCoords.second);

        if (newTile.lock()->isOccupied()) {
            EntityType entityType = newTile.lock()->getEntityType();

            switch (entityType) {
            case EntityType::COIN:
                collectCoin(newCoords.first, newCoords.second);
                movePacman();
                break;

            default:
                pacman.lock()->discardNewPosition();
                break;
            }
        } else {
            movePacman();
        }
    }
}

void Simulator::movePacman() {
    std::weak_ptr<Pacman> pacman = _level->getPacman();
    std::pair<int, int> newCoords = pacman.lock()->getNewPosition();
    pacman.lock()->setPosition(newCoords.first, newCoords.second);

    _level->moveTileEntity(CharacterName::Pacman, newCoords.first, newCoords.second, true);
    _events.push(Event(EventType::pacmanPositionChange, newCoords.first, newCoords.second));
}

} // namespace Logic