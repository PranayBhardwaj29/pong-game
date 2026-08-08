#include "Game.h"

int main()
{
    Game game;
    game.run();
    
    return 0;
}

// to run use this 
//g++ src/*.cpp \
-Iinclude \
-lsfml-graphics \
-lsfml-window \
-lsfml-system \
-o pong

// ./pong