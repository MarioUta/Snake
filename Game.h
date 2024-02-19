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
     Snake snake;
     int appleX,appleY;
     int score;
     char board[26][26];
public:
    Game();
    void getSnake();
    void render();
    void start();
    bool step();

};


#endif //SNAKE_GAME_H
