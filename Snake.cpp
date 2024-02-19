//
// Created by mario on 2/13/24.
//

#include "Snake.h"

Snake::Snake() {
    this->direction = 2;
    this->x = 1;
    this->y = 0;
    head = new Node;
    head->x = 9;
    head->y = 13;
}

int Snake::getX() const {
    return x;
}

int Snake::getY() const {
    return y;
}

int Snake::getCx() const {
    return cx;
}

int Snake::getCy() const {
    return cy;
}

Node *Snake::getHead() const {
    return head;
}

int Snake::getDirection() const {
    return direction;
}

Node *Snake::getTail() const {
    Node *tmp = head;
    while (tmp->next != nullptr)
        tmp = tmp->next;
    return tmp;
}

void Snake::setTail(int a, int b) {
    this->cx = a;
    this->cy = b;
}

void Snake::move(int direction) {
    switch (direction) {
        case 1: //up
            this->x = -1;
            this->y = 0;
            this->direction = 1;
            break;
        case 2://down
            this->x = 1;
            this->y = 0;
            this->direction = 2;
            break;
        case 3://right
            this->x = 0;
            this->y = 1;
            this->direction = 3;
            break;
        case 4://left
            this->x = 0;
            this->y = -1;
            this->direction = 4;
            break;
    }
}

void Snake::eat() {
    Node *tail = getTail();
    Node *extend = new Node;
    extend->x = cx;
    extend->y = cy;
    tail->next = extend;
    extend->prev = tail;
    extend->next = nullptr;
};

Snake::~Snake() {
    remove(getHead());
}



