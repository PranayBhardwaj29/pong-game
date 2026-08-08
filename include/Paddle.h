#pragma once

#include <SFML/Graphics.hpp>

class Paddle
{
private:
    sf::RectangleShape shape;

public:
    Paddle(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::RectangleShape& getShape();

    void move(float amount);
};