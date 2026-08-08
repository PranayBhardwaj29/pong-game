#pragma once

#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::CircleShape shape;

    sf::Vector2f velocity;

public:
    Ball(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::CircleShape& getShape();

    void move();
};