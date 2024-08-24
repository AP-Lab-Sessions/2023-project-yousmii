#ifndef WALL_HPP
#define WALL_HPP
#include "Entity.hpp"

namespace Logic {
/// @brief The wall, but logical this time
class Wall : public Entity {
public:
    /// @brief Constructor of the Wall class
    explicit Wall (const int x, const int y) : Entity(x, y) {_type = EntityType::WALL;}
};

} // Logic

#endif //WALL_HPP
