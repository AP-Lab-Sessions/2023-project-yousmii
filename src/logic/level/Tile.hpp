#ifndef TILE_HPP
#define TILE_HPP
#include "../entities/EntityList.hpp"

#include <memory>

namespace Logic {

typedef std::shared_ptr<Entity> EntityPtr;
typedef std::stack<EntityPtr> EntityStack;

class Tile {
public:
    Tile() = default;
    ~Tile();

    void setEntity(EntityPtr entity, bool isReplacing = false);
    void removeEntity();
    std::weak_ptr<Entity> getEntity() const;
    EntityType getEntityType() const;
    bool isOccupied() const;

private:
    EntityStack _entities;
    bool _isOccupied;
};

} // Logic

#endif //TILE_HPP
