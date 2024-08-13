#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "LevelParser.hpp"
#include <memory>

namespace Logic {

class Level {
public:
    Level(int levelNumber);
    ~Level();

    void loadLevel();

private:
};

} // Logic

#endif //LEVEL_HPP
