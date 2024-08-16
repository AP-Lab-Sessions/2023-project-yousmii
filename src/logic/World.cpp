#include "World.hpp"

#include "level/Level.hpp"

namespace Logic {
World::World(int levelNumber) {
    _level = std::make_shared<Level>(levelNumber);
    _camera = std::make_unique<Camera>(_level);
}

EntityDataMap World::GetFullMap() {
    return _camera->getFullMap();
}

OutputData World::GetOutputData() { return _camera->getOutputData(); }

} // Logic