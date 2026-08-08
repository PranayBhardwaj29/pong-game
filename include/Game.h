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

    sf::Font font;

    int player1Score = 0;  
    int player2Score = 0;

    sf::Text* scoreText;
    sf::Text* startText;
    sf::Text* winnerText;

public:
    Game();

    void run();

    bool gameStarted = false;
    bool gameOver = false;
};