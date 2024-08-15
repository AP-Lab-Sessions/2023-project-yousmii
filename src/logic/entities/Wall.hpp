#ifndef WALL_HPP
#define WALL_HPP
#include "Entity.hpp"

namespace Logic {

class Wall : public Entity {
    // Its a wall, what do you expect? It doesn't move or die or anything. It just exists.
public:
    Wall (int x, int y) : Entity(x, y) {}
};

} // Logic

#endif //WALL_HPP
