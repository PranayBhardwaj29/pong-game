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
    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            paddle1.move(-paddleSpeed * deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            paddle1.move(paddleSpeed * deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            paddle2.move(-paddleSpeed * deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            paddle2.move(paddleSpeed * deltaTime);
        }

        ball.move(deltaTime);

        // Player 1 collision
        if (ball.getShape().getGlobalBounds().findIntersection(paddle1.getShape().getGlobalBounds()))
        {
            ball.bounceX();

            auto ballBounds = ball.getShape().getGlobalBounds();
            auto paddleBounds = paddle1.getShape().getGlobalBounds();

            ball.getShape().setPosition({
                paddleBounds.position.x + paddleBounds.size.x,
                ballBounds.position.y
            });
        }

        // Player 2 collision
        if (ball.getShape().getGlobalBounds().findIntersection(paddle2.getShape().getGlobalBounds()))
        {
            ball.bounceX();

            auto ballBounds = ball.getShape().getGlobalBounds();
            auto paddleBounds = paddle2.getShape().getGlobalBounds();

            ball.getShape().setPosition({
                paddleBounds.position.x - ballBounds.size.x,
                ballBounds.position.y
            });
        }

        window.clear(sf::Color::Black);

        paddle1.draw(window);
        paddle2.draw(window);
        
        ball.draw(window);

        window.display();
    }
}