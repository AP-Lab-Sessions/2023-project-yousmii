#ifndef WALL_HPP
#define WALL_HPP
#include <SFML/Graphics.hpp>

namespace View {

/// @brief Wall class represents the walls in the game. It only holds the sprite
class Wall {
    public:
        /// @brief Constructor for the Wall class. Position the wall at (x, y), doesnt have to change
        explicit Wall(int x, int y);
        ~Wall() = default;

        /// @brief Get the sprite of the wall.
        sf::RectangleShape getSprite() { return _wall; }

    private:
        sf::RectangleShape _wall;
};

} // View

#endif //WALL_HPP
