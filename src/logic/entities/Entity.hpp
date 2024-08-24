#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../../DEFINITIONS.hpp"
#include <utility>

namespace Logic {

typedef std::pair<int,int> Coordinate;

class Entity {
public:
    /// Default constructor
    explicit Entity(int x, int y) : _position(x, y), _spawnPoint(x, y) {};
    ~Entity() = default;

    /// @brief Get the position of the entity
    [[nodiscard]] Coordinate getPosition() const{return _position;}
    /// @brief Get the spawn point of the entity
    [[nodiscard]] Coordinate getSpawnPoint() const { return _spawnPoint; }
    /// @brief Set the position of the entity
    void setPosition(int x, int y) {_position = {x, y};}
    /// @brief Set the spawn point of the entity
    void setSpawnPoint(int x, int y) {_spawnPoint = {x, y};}
    /// @brief Get the entity type
    [[nodiscard]] EntityType getEntityType() const { return _type; }
    /// @brief Get the character name
    [[nodiscard]] CharacterName getCharacterName() const { return _name; }

    /// @brief Reset the entity to its spawn point
    void reset() { _position = _spawnPoint; }
    
protected:
    EntityType _type = EntityType::Empty; // Just really handy to have this to know which child class we are dealing with
    CharacterName _name = CharacterName::None; // Mostly for the ghost class to know which ghost it is
private:
    Coordinate _position;
    Coordinate _spawnPoint;
};

} // Logic

#endif //ENTITY_HPP
