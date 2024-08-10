#include "InputManager.hpp"

namespace View {
template <typename T>
bool InputManager::IsClicked(T object, sf::Mouse::Button button, sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(button)) {
        sf::IntRect rect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width,
                         object.getGlobalBounds().height);

        if (rect.contains(GetMousePosition(window))) {
            return true;
        }
    }
    return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) { return sf::Mouse::getPosition(window); }

void InputManager::checkClose(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

} // namespace View