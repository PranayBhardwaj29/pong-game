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

void Paddle::move(float amount)
{
    // This get us the position of the paddle
    sf::Vector2f pos = shape.getPosition();
    float currentX = pos.x;
    float currentY = pos.y;
    // The paddle moves by a certain amount in Y direction
    float newYPositition = currentY + amount;
    // We set the new position to paddle
    shape.setPosition({currentX, newYPositition});
}