
#include "Wall.hpp"

#include "DEFINITIONS.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "view/COLORS.hpp"

namespace View {
    Wall::Wall(int x, int y) {
        _wall = sf::RectangleShape(sf::Vector2f(SPRITE_WIDTH, SPRITE_HEIGHT));
        _wall.setScale(SPRITE_SCALE, SPRITE_SCALE);
        _wall.setFillColor(Color::BLUE);
        _wall.setPosition(x, y);
    }

} // View