#include "Tile.hpp"

namespace Logic {
void Tile::setEntity(std::shared_ptr<Entity> entity) {
    _entity = std::move(entity);
    _isOccupied = true;
}

std::weak_ptr<Entity> Tile::getEntity() const { return std::weak_ptr<Entity>(_entity); }

bool Tile::isOccupied() const { return _isOccupied; }

EntityType Tile::getEntityType() const {
    if (isOccupied()) {
        return _entity->getEntityType();
    }
    return EntityType::Empty;
}

} // namespace Logic