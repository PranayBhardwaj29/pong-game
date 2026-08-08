#include "Game.h"
const float paddleSpeed = 500.f;

Game::Game()
    : window(sf::VideoMode({1600, 900}), "Pong"),
      paddle1(50.f, 350.f),
      paddle2(1500.f, 350.f),
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            paddle1.move(-paddleSpeed / 60.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            paddle1.move(paddleSpeed / 60.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            paddle2.move(-paddleSpeed / 60.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            paddle2.move(paddleSpeed / 60.f);
        }

        ball.move();

        window.clear(sf::Color::Black);

        paddle1.draw(window);
        paddle2.draw(window);
        
        ball.draw(window);

        window.display();
    }
}