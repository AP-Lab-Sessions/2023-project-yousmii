#include "Tile.hpp"

namespace Logic {
void Tile::setEntity(EntityPtr entity, bool isReplacing) {
    if (isOccupied()) {
        if (isReplacing) {
            _entities.pop();
        }
    }
    _entities.push(std::move(entity));
    _isOccupied = true;
}

void Tile::removeEntity() {
    if (isOccupied()) {
        _entities.pop();
        if (_entities.empty()) {
            _isOccupied = false;
        }
    }
}

std::weak_ptr<Entity> Tile::getEntity() const { return std::weak_ptr<Entity>(_entities.top()); }

bool Tile::isOccupied() const { return _isOccupied; }

EntityType Tile::getEntityType() const {
    if (isOccupied()) {
        return _entities.top()->getEntityType();
    }
    return EntityType::Empty;
}

} // namespace Logic