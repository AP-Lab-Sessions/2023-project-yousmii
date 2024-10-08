// Source: SFML Game Engine by Sonar Systems

#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace View {

class InputManager {
public:
    InputManager() = default;
    ~InputManager() = default;

    /// @brief Check if the object is clicked, not used in this project, but leaving it here if ever needed
    template <typename T>
    bool IsClicked(T object, sf::Mouse::Button button, sf::RenderWindow& window);

    /// @brief Check if the window is closed
    /// @remark Made to be used in the main loop, just avoids a lot of duplicate code
    void checkClose(sf::RenderWindow& window);

    /// @brief Get the mouse position in the window
    sf::Vector2i GetMousePosition(sf::RenderWindow& window);
};

} // namespace View

#endif // INPUTMANAGER_HPP
