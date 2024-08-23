#ifndef WORLD_HPP
#define WORLD_HPP
#include "../DEFINITIONS.hpp"
#include "../singletons/Stopwatch.hpp"
#include "Camera.hpp"
#include "Simulator.hpp"
#include "level/Level.hpp"

#include <memory>

namespace Logic {

struct WorldData {
    unsigned int width;
    unsigned int height;
    Singletons::Stopwatch stopwatch = Singletons::Stopwatch::GetInstance();

};

typedef std::shared_ptr<WorldData> WorldDataPtr;

class World {
public:
    World(int levelNumber);

    void Start();
    void Update(float dt);

    EntityDataMap GetFullMap();
    void GetUpdates();
    OutputData GetOutputData();

    void SetPlayerDirection(Direction direction);

private:
    SimulatorPtr _simulator;
    CameraPtr _camera;
};

} // Logic

#endif //WORLD_HPP
