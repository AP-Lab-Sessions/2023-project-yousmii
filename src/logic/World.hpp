#ifndef WORLD_HPP
#define WORLD_HPP
#include <memory>

namespace Logic {

struct WorldData {
    unsigned int width;
    unsigned int height;

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
