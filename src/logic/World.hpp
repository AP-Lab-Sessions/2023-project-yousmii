#ifndef WORLD_HPP
#define WORLD_HPP
#include "../singletons/Stopwatch.hpp"

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
    World();

    void Start();
    void Update(float dt);

    void SetPlayerDirection(int direction);
};

} // Logic

#endif //WORLD_HPP
