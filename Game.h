//
// Created by mario on 2/13/24.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "colors.h"
#include "Snake.h"
#include <string>

using namespace std;

class Game {
private:
    static Snake snake;
    static int appleX, appleY;
    static int score;
    static char board[26][26];
    static void getSnake();
    static void render();
    static bool step();

public:
    Game();
    static void start();

};


#endif //SNAKE_GAME_H
