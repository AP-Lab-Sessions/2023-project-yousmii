#include "World.hpp"

#include "level/Level.hpp"

namespace Logic {
World::World(int levelNumber) {
    LevelPtr level = std::make_shared<Level>(levelNumber);
    _simulator = std::make_unique<Simulator>(std::move(level));
    _camera = std::make_unique<Camera>(std::move(_simulator->getLevel()));
}

EntityDataMap World::GetFullMap() {
    return _camera->getFullMap();
}

OutputData World::GetOutputData() { return _camera->getOutputData(); }

void World::SetPlayerDirection(Direction direction) { _simulator->getLevel().lock()->setPlayerDirection(direction); }

} // Logic