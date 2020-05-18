//
// Created by Ivan on 04.02.2020.
//

#include "MyQueue.h"

void MyQueue::push(Bullet n) {
    bullets[++mBackPos] = n;
}

void MyQueue::pop(int j) {
    while (j < mBackPos) {
        std::swap(bullets[j], bullets[j + 1]);
        j++;
    }
    mBackPos--;
}

int MyQueue::size() const {
    return mBackPos + 1;
}
