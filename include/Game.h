#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Game {
private:
    sf::RenderWindow window;

    Paddle paddle1;
    Paddle paddle2;
    
    sf::CircleShape ball;

public:
    Game();

    void run();
};