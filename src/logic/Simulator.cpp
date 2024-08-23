#include "Simulator.hpp"

#include <iostream>

namespace Logic {
Simulator::Simulator(LevelPtr level) : _level(std::move(level)) {
    std::cout << "Simulator created" << std::endl;

}

Simulator::~Simulator() {
    std::cout << "Simulator destroyed" << std::endl;
}
void Simulator::update() {

}

std::weak_ptr<Level> Simulator::getLevel() {
    return std::weak_ptr<Level>(_level);
}

} // Logic