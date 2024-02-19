//
// Created by mario on 2/13/24.
//

#include "Game.h"
#include <cstdlib>
#include <ctime>

Snake Game::snake;
int Game::appleX, Game::appleY;
int Game::score;
char Game::board[26][26];

void Game::getSnake() {
    Node *node = snake.getHead();
    board[node->x][node->y] = 'O';
    node = node->next;
    while (node) {
        board[node->x][node->y] = '#';
        node = node->next;
    }
}

void Game::render() {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            board[i][j] = ' ';
        }
    }

    getSnake();

    board[appleX][appleY] = '*';

    cout << "Score:" << score << endl;

    cout << " ";
    for (int i = 0; i <= 51; ++i) {
        cout << "_";
    }

    cout << endl;
    for (int i = 0; i < 26; ++i) {
        cout << "|";
        for (int j = 0; j < 26; ++j) {

            if (board[i][j] == '*')
                cout << "\033[1;31m" << board[i][j] << "\033[0m" << " ";
            else if (board[i][j] == '#')
                cout << "\033[1;32m" << board[i][j] << "\033[0m" << " ";
            else if (board[i][j] == 'O')
                cout << "\033[1;33m" << board[i][j] << "\033[0m" << " ";
            else
                cout << board[i][j] << " ";

        }
        cout << "|";
        cout << endl;
    }
    cout << " ";
    for (int i = 0; i <= 51; ++i) {
        cout << "_";
    }
    cout << endl;
}

bool Game::step() {
    Node *node = snake.getTail();
    snake.setTail(node->x, node->y);
    while (node->prev != nullptr) {
        node->x = node->prev->x;
        node->y = node->prev->y;
        node = node->prev;
    }

    node->x = (node->x + snake.getX()) % 26;
    if (node->x == -1)
        node->x = 25;

    node->y = (node->y + snake.getY()) % 26;
    if (node->y == -1)
        node->y = 25;

    if (board[node->x][node->y] == '#' && (node->x != snake.getCx() || node->y != snake.getCy())) {
        return false;
    }

    if (board[node->x][node->y] == '*') {
        snake.eat();
        int apple = rand() % 625;
        appleX = apple / 25;
        appleY = apple % 25;
        score++;
    }
    return true;
}

void Game::start() {

    step();
    snake.eat();
    step();
    snake.eat();
    step();
    snake.eat();
    step();
    snake.eat();

    srand(time(0));

    int apple = rand() % 625;
    appleX = apple / 25;
    appleY = apple % 25;
    score = 0;

    int ok = true;
    set_raw_mode(true);
    while (ok) {
        int ch = quick_read();

        if (ch == ERR);
        else if (ch == 'w') {
            if (snake.getDirection() != 2)
                snake.move(1);
        } else if (ch == 's') {
            if (snake.getDirection() != 1)
                snake.move(2);
        } else if (ch == 'a') {
            if (snake.getDirection() != 3)
                snake.move(4);
        } else if (ch == 'd') {
            if (snake.getDirection() != 4)
                snake.move(3);
        } else if (ch == 'e') { snake.eat(); }

        ok = step();
        render();

        usleep(150000);
        cout << "\033[H\033[2J\033[3J";
    }
    cout << "Game over!" << endl;
    cout << "Your score:" << score << endl;
}