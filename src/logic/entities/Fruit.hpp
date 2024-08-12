
#ifndef FRUIT_HPP
#define FRUIT_HPP

namespace Logic {

class Fruit {
public:
    void eat();
    [[nodiscard]] bool isEaten() const { return _isEaten; }

private:
    bool _isEaten = false;

};

} // Logic

#endif //FRUIT_HPP
