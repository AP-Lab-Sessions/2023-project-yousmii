#ifndef TILE_HPP
#define TILE_HPP
#include "../entities/Entity.hpp"

#include <memory>

namespace Logic {

class Tile {
public:
    Tile() = default;
    ~Tile() = default;

    void setEntity(std::unique_ptr<Entity> entity);
    Entity* getEntity() const;
    bool isOccupied() const;

private:
    std::unique_ptr<Entity> _entity;
    bool _isOccupied;
};

} // Logic

#endif //TILE_HPP
