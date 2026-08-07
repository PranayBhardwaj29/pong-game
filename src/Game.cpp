#include "Game.h"

Game::Game()
    : window(sf::VideoMode({1600, 900}), "Pong"),
      paddle1(100.f, 350.f),
      paddle2(1450.f, 350.f),
      ball(750.f, 400.f)
{
    window.setFramerateLimit(60);
}

void Game::run()
{
    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        paddle1.draw(window);
        paddle2.draw(window);
        
        ball.draw(window);

        window.display();
    }
}