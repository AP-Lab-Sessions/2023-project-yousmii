#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <random>
namespace Singletons {

/// Singleton class for generating random numbers
class RNG {
public:
    /// @brief Get the instance of the RNG
    static RNG getInstance();
    /// @brief Get a random integer
    int getRandomInt(int min = 1, int max = 100);

private:
    RNG() = default;
    /// @brief The random number generator
    std::mt19937 generator;
};

} // namespace Singletons

#endif // RANDOMIZER_HPP
