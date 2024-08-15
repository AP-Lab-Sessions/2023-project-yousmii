#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../../DEFINITIONS.hpp"
#include <utility>

namespace Logic {

typedef std::pair<int,int> Coordinate;

class Entity {
public:
    Entity(int x, int y) : _position(x, y), _spawnPoint(x, y) {};
    virtual ~Entity() = default;

    [[nodiscard]] Coordinate getPosition() const{return _position;}
    [[nodiscard]] Coordinate getSpawnPoint() const { return _spawnPoint; }
    void setPosition(int x, int y) {_position = {x, y};}
    void setSpawnPoint(int x, int y) {_spawnPoint = {x, y};}
    [[nodiscard]] EntityType getEntityType() const { return _type; }
    [[nodiscard]] CharacterName getCharacterName() const { return _name; }

    EntityType _type; // Just really handy to have this to know which child class we are dealing with
    CharacterName _name = CharacterName::None; // Mostly for the ghost class to know which ghost it is
private:
    Coordinate _position;
    Coordinate _spawnPoint;
};

} // Logic

#endif //ENTITY_HPP
