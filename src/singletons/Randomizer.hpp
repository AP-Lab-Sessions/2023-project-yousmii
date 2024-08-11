#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <random>
namespace Singletons {

/// Singleton class for generating random numbers
class RNG {
public:
    static RNG getInstance();
    int getRandomInt(int min = 1, int max = 100);

private:
    RNG() = default;
    std::mt19937 generator;
};

} // namespace Singletons

#endif // RANDOMIZER_HPP
