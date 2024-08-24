#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>

namespace Singletons {

/// @brief The Stopwatch class is responsible for measuring time differences between frames.
class Stopwatch {
public:
    static Stopwatch& GetInstance() {
        static Stopwatch instance;
        return instance;
    }
    /// @brief Start the stopwatch
    void Start();

    /// @brief Tick, update the frame time
    void Tick();

    /// @brief Get the time between frames
    [[nodiscard]] float GetFrameTime();

private:
    Stopwatch() = default;

    /// @brief Last time the frame was updated
    std::chrono::time_point<std::chrono::high_resolution_clock> _start = std::chrono::high_resolution_clock::now();
    /// @brief Delta time, time between frames
    std::chrono::milliseconds dt = std::chrono::milliseconds(0);
};

} // namespace Singletons

#endif // STOPWATCH_HPP
