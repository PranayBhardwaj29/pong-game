#include "Paddle.h"

Paddle::Paddle(float x, float y)
{
    shape.setSize({50.f, 200.f});
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color::White);
}

void Paddle::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::RectangleShape& Paddle::getShape()
{
    return shape;
}