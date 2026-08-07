#pragma once

#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow window;
    sf::RectangleShape paddle1, paddle2;
    sf::CircleShape ball;

public:
    Game();
    void run();
};