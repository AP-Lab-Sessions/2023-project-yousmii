#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game{
public:
        Game();
        ~Game();
        void run();

private:
    void render();
    void update();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    sf::RenderWindow mWindow;
};

#endif // GAME_H