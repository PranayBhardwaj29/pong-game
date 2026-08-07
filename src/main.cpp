#include "Game.h"

int main()
{
    Game game;
    game.run();
    
    return 0;
}

// To run code use this in terminal g++ src/main.cpp src/Game.cpp -Iinclude -lsfml-graphics -lsfml-window -lsfml-system -o pong
// ./pong