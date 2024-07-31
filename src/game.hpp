#ifndef GAME_H
#define GAME_H

#include "state.hpp"
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

namespace Rep {
class Game {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800u, 600u), "CPPacman");
};
} // namespace Rep

#endif // GAME_H
