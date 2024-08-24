#ifndef TILE_HPP
#define TILE_HPP
#include "../entities/EntityList.hpp"

#include <memory>

namespace Logic {

typedef std::shared_ptr<Entity> EntityPtr;
typedef std::stack<EntityPtr> EntityStack;

/// @brief The Tile class represents a single tile on the level grid.
class Tile {
public:
    Tile() = default;
    ~Tile();

    /// @brief Sets the entity of the tile.
    /// @param entity The entity to set.
    /// @param isReplacing If the entity is replacing another entity. Default is false.
    /// @remark Very useful for eating coins and powerups.
    void setEntity(EntityPtr entity, bool isReplacing = false);

    /// @brief Removes the entity from the tile.
    /// @return The entity that was removed. You can use this to add it to another tile.
    EntityPtr removeEntity();

    /// @brief Returns the entity of the tile.
    /// @return Weak pointer to the entity of the tile, remember to check if it is expired.
    [[nodiscard]] std::weak_ptr<Entity> getEntity() const;
    /// @brief Returns the entity type of the tile.
    [[nodiscard]] EntityType getEntityType() const;
    /// @brief Returns if the tile is occupied.
    [[nodiscard]] bool isOccupied() const;

private:
    /// @brief The entity stack of the tile
    EntityStack _entities;
    bool _isOccupied = false;
};

} // Logic

#endif //TILE_HPP
