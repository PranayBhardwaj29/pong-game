#include "Ball.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

const float maxBallSpeed = 1100.f;

Ball::Ball(float x, float y)
{
    shape.setRadius(50.f);
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color::Red);

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    float randomY;

    do
    {
        randomY = static_cast<float>((std::rand() % 601) - 300);
    }
    while (std::abs(randomY) < 150);

    velocity = {
        (std::rand() % 2 == 0 ? 500.f : -500.f),
        randomY
    };
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::CircleShape& Ball::getShape()
{
    return shape;
}

void Ball::move(float deltaTime)
{
    sf::Vector2f pos = shape.getPosition();
    float currentX = pos.x;
    float currentY = pos.y;
    
    float newX = currentX + velocity.x * deltaTime;
    float newY = currentY + velocity.y * deltaTime;
    
    if (newY < 50 || newY > 800)
    {
        velocity.y = -velocity.y;
    }

    shape.setPosition({newX, newY});
}

void Ball::bounceX()
{
    velocity.x = -velocity.x;
}

void Ball::speedUp()
{
    velocity *= 1.1f;

    if (std::abs(velocity.x) > maxBallSpeed)
    {
        velocity.x = (velocity.x > 0) ? maxBallSpeed : -maxBallSpeed;
    }

    if (std::abs(velocity.y) > maxBallSpeed)
    {
        velocity.y = (velocity.y > 0) ? maxBallSpeed : -maxBallSpeed;
    }
}

void Ball::changeAngle()
{
    // Get current speed
    float speed = std::sqrt(
        velocity.x * velocity.x + velocity.y * velocity.y
    );

    // Random angle between 20 and 60 degrees
    float angle = static_cast<float>(
        (std::rand() % 41) + 20
    );

    // Convert degrees to radians
    float radians = angle * 3.14159265f / 180.f;

    // Keep the current horizontal direction
    float directionX = velocity.x > 0 ? 1.f : -1.f;

    // Randomly choose whether the ball goes up or down
    float directionY = (std::rand() % 2 == 0) ? 1.f : -1.f;

    velocity.x = directionX * speed * std::cos(radians);
    velocity.y = directionY * speed * std::sin(radians);
}

void Ball::reset() 
{
    shape.setPosition({750.f, 400.f});
    
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    float randomY;

    do
    {
        randomY = static_cast<float>((std::rand() % 601) - 300);
    }
    while (std::abs(randomY) < 150);

    velocity = {
        (std::rand() % 2 == 0 ? 500.f : -500.f),
        randomY
    };
}