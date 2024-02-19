//
// Created by mario on 2/13/24.
//

#include "Snake.h"

Snake::Snake() {
    this->direction=2;
    this->x = 1;
    this->y = 0;
    head = new Node;
    head->x = 9;
    head->y = 13;
    /*
    Node *second = new Node, *third = new Node, *forth = new Node, *fifth = new Node;
    head->prev = nullptr;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = forth;
    forth->prev = third;
    forth->next = fifth;
    fifth->prev = forth;
    fifth->next = nullptr;
    second->x = 12;
    second->y = 13;
    third->x = 11;
    third->y = 13;
    forth->x = 10;
    forth->y = 13;
    fifth->x = 9;
    fifth->y = 13;
     */
}

void Snake::move(int direction) {
    switch (direction) {
        case 1: //up
            this->x = -1;
            this->y = 0;
            this->direction=1;
            break;
        case 2://down
            this->x = 1;
            this->y = 0;
            this->direction=2;
            break;
        case 3://right
            this->x = 0;
            this->y = 1;
            this->direction=3;
            break;
        case 4://left
            this->x = 0;
            this->y = -1;
            this->direction=4;
            break;
    }
}

Snake::~Snake() {
    remove(getHead());
}

int Snake::getCx() const {
    return cx;
}

int Snake::getCy() const {
    return cy;
}

int Snake::getDirection() const {
    return direction;
}



