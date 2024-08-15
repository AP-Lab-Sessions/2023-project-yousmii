#ifndef WALL_HPP
#define WALL_HPP
#include "Entity.hpp"

namespace Logic {

class Wall : public Entity {
public:
    Wall (int x, int y) : Entity(x, y) {_type = EntityType::WALL;}
};

} // Logic

#endif //WALL_HPP
