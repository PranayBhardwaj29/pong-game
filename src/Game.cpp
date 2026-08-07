#include "Game.h"

Game::Game()
    : window(sf::VideoMode({1600, 900}), "Pong")
{
    
    // Paddle 1
    paddle1.setSize({20.f, 150.f});
    paddle1.setPosition({50.f, 375.f});
    paddle1.setFillColor(sf::Color::White);
    
    // Paddle 2
    paddle2.setSize({20.f, 150.f});
    paddle2.setPosition({1530.f, 375.f});
    paddle2.setFillColor(sf::Color::White);
    
    // Ball
    ball.setRadius(10.f);
    ball.setPosition({790.f, 440.f});
    ball.setFillColor(sf::Color::White);
}

void Game::run()
{
    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear();

        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(ball);

        window.display();
    }
}