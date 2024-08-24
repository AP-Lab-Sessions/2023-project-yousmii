#ifndef SCORE_HPP
#define SCORE_HPP
#include <memory>

namespace Logic {

class Score {
public:
    /// @ brief Constructor of the Score class, initializes the score to 2000.
    Score();
    ~Score() = default;

    /// @brief Adds the given value to the score.
    /// @param value The value to be added to the score.
    void addScore(int value);

    /// @brief Subtracts the given value from the score.
    /// @param value The value to be subtracted from the score.
    void subtractScore(int value);

    /// @brief Returns the current score.
    int getScore() const;

private:
    int _score;
};

typedef std::shared_ptr<Score> ScorePtr;

} // Logic

#endif //SCORE_HPP
