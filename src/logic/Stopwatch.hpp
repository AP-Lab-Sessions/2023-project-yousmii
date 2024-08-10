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

    [[nodiscard]] float GetFrameTime();

private:
    Stopwatch() = default;

    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
    std::chrono::seconds dt;
};

} // namespace Logic

#endif // STOPWATCH_HPP
