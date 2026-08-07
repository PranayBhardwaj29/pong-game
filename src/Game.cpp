#include "Game.h"

Game::Game()
    : window(sf::VideoMode({1600, 900}), "Pong")
{
    window.setFramerateLimit(60);

    paddle1.setSize({50.f, 200.f});
    paddle1.setPosition({100.f, 350.f});
    paddle1.setFillColor(sf::Color::White);

    paddle2.setSize({50.f, 200.f});
    paddle2.setPosition({1450.f, 350.f});
    paddle2.setFillColor(sf::Color::White);

    ball.setRadius(50.f);
    ball.setPosition({750.f, 400.f});
    ball.setFillColor(sf::Color::Red);
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


        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(ball);


        window.display();
    }
}