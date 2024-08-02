#include "SplashState.hpp"

#include <iostream>

namespace View {
SplashState::SplashState(GameDataRef data) : _data(data) {}

void SplashState::Init() {
    std::cout << "SplashState initialised" << std::endl;

}
} // namespace View