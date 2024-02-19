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
    int cx,cy;
    Node *head;
    void remove(Node *node) {
        if (node->next != nullptr)
            remove(node->next);
        delete node;
    };
public:
    Snake();

    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    void move(int direction);

    void eat() {
        Node * tail =getTail();
        Node * extend= new Node;
        extend->x=cx;
        extend->y=cy;
        tail->next=extend;
        extend->prev=tail;
        extend->next= nullptr;
    };

    int getCx() const;

    int getCy() const;

    Node *getHead() const {
        return head;
    }

    void setTail(int a,int b){
        this->cx=a;
        this->cy=b;
    }

    int getDirection() const;

    Node *getTail() const {
        Node *tmp = head;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        return tmp;
    }

    ~Snake();
};


#endif //SNAKE_SNAKE_H
