#include "Ball.h"

Ball::Ball(float x, float y)
{
    shape.setRadius(50.f);
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color::Red);
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::CircleShape& Ball::getShape()
{
    return shape;
}