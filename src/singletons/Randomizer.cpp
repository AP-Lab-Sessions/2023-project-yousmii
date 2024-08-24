#include "Randomizer.hpp"

namespace Singletons {

RNG RNG::getInstance() {
    static RNG instance;
    return instance;
}
int RNG::getRandomInt(const int min, const int max) {
    generator.seed(std::random_device()()); // Seed the generator
    std::uniform_int_distribution<int> distribution(min, max); // Define the range
    return distribution(generator); // Generate the number
}
} // namespace Singletons