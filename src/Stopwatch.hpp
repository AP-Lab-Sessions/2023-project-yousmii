#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>

namespace Logic {

class Stopwatch {
public:
    static Stopwatch& GetInstance() {
        static Stopwatch instance;
        return instance;
    }
    void Start();
    void Tick();

    [[nodiscard]] std::chrono::milliseconds GetElapsedTime();

private:
    Stopwatch() = default;

    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
    std::chrono::milliseconds dt;
};

} // namespace Logic

#endif // STOPWATCH_HPP
