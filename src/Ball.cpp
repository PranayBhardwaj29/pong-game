#include "Ball.h"

Ball::Ball(float x, float y)
{
    shape.setRadius(50.f);
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color::Red);

    velocity = {5.f, 3.f};
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::CircleShape& Ball::getShape()
{
    return shape;
}

void Ball::move()
{
    sf::Vector2f pos = shape.getPosition();
    float currentX = pos.x;
    float currentY = pos.y;
    
    float newX = currentX + velocity.x;
    float newY = currentY + velocity.y;

    shape.setPosition({newX, newY});
}