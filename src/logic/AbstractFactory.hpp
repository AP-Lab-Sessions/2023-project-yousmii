#ifndef ABSTRACTFACTORY_HPP
#define ABSTRACTFACTORY_HPP

namespace Logic {

class AbstractFactory {
public:
    AbstractFactory();
    ~AbstractFactory();

    void createPacMan();
    void createGhost();
    void createWall();
    void createFruit();
    void createCoin();
    void createLevel();
};

} // Logic

#endif //ABSTRACTFACTORY_HPP
