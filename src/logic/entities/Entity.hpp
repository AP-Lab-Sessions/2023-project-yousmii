#ifndef ENTITY_HPP
#define ENTITY_HPP
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

private:
    Coordinate _position;
    Coordinate _spawnPoint;
};

} // Logic

#endif //ENTITY_HPP
