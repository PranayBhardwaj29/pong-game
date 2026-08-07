#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"

class Game {
private:
    sf::RenderWindow window;

    Paddle paddle1;
    Paddle paddle2;
    
    Ball ball;

public:
    Game();

    void run();
};