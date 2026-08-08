#include "Game.h"
#include <string>

const float paddleSpeed = 500.f;

Game::Game()
    : window(sf::VideoMode({1600, 900}), "Pong"),
      paddle1(50.f, 350.f),
      paddle2(1500.f, 350.f),
      ball(750.f, 400.f)
{
    window.setFramerateLimit(60);

    font.openFromFile("font/LiberationSans-Regular.ttf");

    startText = new sf::Text(font, "Press Enter to Start", 40);
    startText->setPosition({600.f, 400.f});

    scoreText = new sf::Text(font, "0   0", 50);
    scoreText->setPosition({750.f, 30.f});

    winnerText = new sf::Text(font, "", 50);
    winnerText->setPosition({600.f, 400.f});
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            if (gameOver)
            {
                player1Score = 0;
                player2Score = 0;

                scoreText->setString(
                    std::to_string(player1Score) + "   " +
                    std::to_string(player2Score)
                );

                gameOver = false;
                ball.reset();
                gameStarted = true;
            }
            else
            {
                gameStarted = true;
            }
        }

        if (gameStarted)
        {
            ball.move(deltaTime);
        }

        auto ballBounds = ball.getShape().getGlobalBounds();

        if (ballBounds.position.x + ballBounds.size.x < 0) {
            // Player 2 scores
            player2Score++;
            scoreText->setString(
                std::to_string(player1Score) + "   " +
                std::to_string(player2Score)
            );

            if (player2Score >= 5)
            {
                winnerText->setString("Player 2 Wins!");
                gameOver = true;
                gameStarted = false;
            }

            gameStarted = false;
            ball.reset();
        }

        if (ballBounds.position.x > 1600) {
            // Player 1 scores
            player1Score++;
            scoreText->setString(
                std::to_string(player1Score) + "   " +
                std::to_string(player2Score)
            );

            if (player1Score >= 5)
            {
                winnerText->setString("Player 1 Wins!");
                gameOver = true;
                gameStarted = false;
            }

            gameStarted = false;
            ball.reset();
        }

        // Player 1 collision
        if (ball.getShape().getGlobalBounds().findIntersection(
                paddle1.getShape().getGlobalBounds()))
        {
            ball.bounceX();
            ball.speedUp();
            ball.changeAngle();

            auto ballBounds = ball.getShape().getGlobalBounds();
            auto paddleBounds = paddle1.getShape().getGlobalBounds();

            ball.getShape().setPosition({
                paddleBounds.position.x + paddleBounds.size.x,
                ballBounds.position.y
            });
        }

        // Player 2 collision
        if (ball.getShape().getGlobalBounds().findIntersection(
                paddle2.getShape().getGlobalBounds()))
        {
            ball.bounceX();
            ball.speedUp();
            ball.changeAngle();

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

        window.draw(*scoreText);

        if (!gameStarted  && !gameOver)
        {
            window.draw(*startText);
        }

        if (gameOver)
        {
            window.draw(*winnerText);
        }

        window.display();
    }
}