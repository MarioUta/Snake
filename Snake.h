//
// Created by mario on 2/13/24.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

struct Node {
    int x;
    int y;
    Node *next;
    Node *prev;
};

class Snake {
private:
    int direction;
    int x, y;
    int cx, cy;
    Node *head;

    void remove(Node *node) {
        if (node->next != nullptr)
            remove(node->next);
        delete node;
    };
public:
    Snake();

    int getX() const;

    int getY() const;

    int getCx() const;

    int getCy() const;

    Node *getHead() const;

    int getDirection() const;

    Node *getTail() const;

    void setTail(int a, int b);

    void move(int direction);

    void eat();

    ~Snake();
};


#endif //SNAKE_SNAKE_H
