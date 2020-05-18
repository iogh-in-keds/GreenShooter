//
// Created by Ivan on 04.02.2020.
//

#ifndef UNTITLED3_MYQUEUE_H
#define UNTITLED3_MYQUEUE_H

#include "Bullet.h"

class MyQueue {
public:
    void push(Bullet n);

    void pop(int j);

    int size() const;

    Bullet bullets[150];

private:
    int mBackPos = -1;
};


#endif //UNTITLED3_MYQUEUE_H
