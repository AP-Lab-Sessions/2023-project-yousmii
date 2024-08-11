#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <utility>

namespace Logic {

typedef std::pair<unsigned int, unsigned int> Coordinate;

class Entity {
public:
    Entity(int x, int y) : position(x, y), spawnPoint(x, y) {};
    virtual ~Entity() = default;

    [[nodiscard]] Coordinate getPosition() const{return position;}
    [[nodiscard]] Coordinate getSpawnPoint() const { return spawnPoint; }
    void setPosition(int x, int y) : position(x, y) {}
    void setSpawnPoint(int x, int y): spawnPoint(x, y){}

private:
    Coordinate position;
    Coordinate spawnPoint;
};

} // Logic

#endif //ENTITY_HPP
