//
// Created by maerrey on 11/08/2024.
//

#include "Tile.hpp"

namespace Logic {
void Tile::setEntity(std::shared_ptr<Entity> entity) {
    _entity = std::move(entity);
    _isOccupied = true;
}

std::weak_ptr<Entity> Tile::getEntity() const { return std::weak_ptr<Entity>(_entity); }

} // namespace Logic