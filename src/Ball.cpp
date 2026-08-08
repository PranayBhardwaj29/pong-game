#include "Ball.h"
#include <cstdlib>
#include <ctime>

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