#ifndef TILE_HPP
#define TILE_HPP
#include "../entities/EntityList.hpp"

#include <memory>

namespace Logic {

class Tile {
public:
    Tile() = default;
    ~Tile() = default;

    void setEntity(std::shared_ptr<Entity> entity);
    std::weak_ptr<Entity> getEntity() const;
    bool isOccupied() const;

private:
    std::shared_ptr<Entity> _entity;
    bool _isOccupied;
};

} // Logic

#endif //TILE_HPP
