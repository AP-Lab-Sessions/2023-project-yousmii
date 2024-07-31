#include "Stopwatch.hpp"

namespace Logic {
void Stopwatch::Start() { _start = std::chrono::high_resolution_clock::now(); }

void Stopwatch::Tick() {
    std::chrono::system_clock::time_point now = std::chrono::high_resolution_clock::now();

    dt = std::chrono::duration_cast<std::chrono::milliseconds>(now - _start);
    _start = now;
}

    [[nodiscard]] std::chrono::milliseconds Stopwatch::GetElapsedTime() { return dt; }
} // namespace Logic