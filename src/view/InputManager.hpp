// Source: SFML Game Engine by Sonar Systems

#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace View {

class InputManager {
public:
    InputManager() = default;
    ~InputManager() = default;

    template <typename T>
    bool IsClicked(T object, sf::Mouse::Button button, sf::RenderWindow& window);

    void checkClose(sf::RenderWindow& window);

    sf::Vector2i GetMousePosition(sf::RenderWindow& window);
};

} // namespace View

#endif // INPUTMANAGER_HPP
