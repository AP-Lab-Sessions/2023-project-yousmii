// Source: SFML Game Engine by Sonar Systems

#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace Rep {

class InputManager {
public:
    InputManager() = default;
    ~InputManager() = default;

    bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

    sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};

} // Rep

#endif //INPUTMANAGER_HPP
