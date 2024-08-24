#include "Tile.hpp"

#include <stdexcept>

namespace Logic {
Tile::~Tile() {
    if (isOccupied()) {
        _entities.pop();
    }
}
void Tile::setEntity(EntityPtr entity, bool isReplacing) {
    if (isOccupied()) {
        if (isReplacing) {
            _entities.pop();
        }
    }
    _entities.push(std::move(entity));
    _isOccupied = true;
}

EntityPtr Tile::removeEntity() {
    if (isOccupied()) {
        EntityPtr entity = std::move(_entities.top());
        _entities.pop();
        if (_entities.empty()) {
            _isOccupied = false;
        }
        return entity;
    }
    throw std::runtime_error("No entity to remove");
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