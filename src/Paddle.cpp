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
    float newYPosition = currentY + amount;

    // check if newYposition does not go above the boundary
    if (newYPosition < 0) {
        newYPosition = 0;
    }

    // check if newYposition does not go below the boundary or window
    if (newYPosition > 700) {
        newYPosition = 700;
    }
    
    // We set the new position to paddle
    shape.setPosition({currentX, newYPosition});
}