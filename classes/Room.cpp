//
// Created by Ivan on 26.02.2020.
//

#include "Room.h"

Room::Room() {
    mX = 0;
    mY = 0;

}

void Room::setImage(const String &string) {
    mImage.loadFromFile(string);
    for (int i = 0; i < 600; i += 30) {
        for (int j = 0; j < 600; j += 30) {
            if (mImage.getPixel(i, j) == mImage.getPixel(0, 0)) {
                mWall.resize(mNumberOfWall + 1);
                mWall[mNumberOfWall++] = new Wall(Vector2f(150 + i, 50 + j));
            }
            if (mImage.getPixel(i, j) == mImage.getPixel(0, 2)) {
                mTurret.resize(mNumberOfTurret + 1);
                mTurret[mNumberOfTurret++] = new Turret(1, 1, 150.f + i, 50.f + j);
            }
            if (mImage.getPixel(i, j) == mImage.getPixel(0, 1)) {
                boss.setPosition(150.f + i, 50.f + j);
            }
        }
    }
    mWaitTurret.resize(mNumberOfTurret);
    for (int i = 0; i < mNumberOfTurret; i++) {
        mWaitTurret[i] = 0;
    }
    if (mX == 0) {
        mWall.resize(mNumberOfWall + 1);
        mWall[mNumberOfWall++] = new Wall(Vector2f(150, 350));
    }
    if (mX == 1) {
        mWall.resize(mNumberOfWall + 1);
        mWall[mNumberOfWall++] = new Wall(Vector2f(720, 350));
    }
    if (mY == 0) {
        mWall.resize(mNumberOfWall + 1);
        mWall[mNumberOfWall++] = new Wall(Vector2f(420, 50));
    }
    if (mY == 1) {
        mWall.resize(mNumberOfWall + 1);
        mWall[mNumberOfWall++] = new Wall(Vector2f(420, 620));
    }
}

void Room::setPosition(int x, int y) {
    mX = x;
    mY = y;
}

//int Room::getX() {
//    return mX;
//}
//
//int Room::getY() {
//    return mY;
//}

void Room::turretHit(MyQueue &array, float damage) {
    for (int i = 0; i < mNumberOfTurret; i++) {
        for (int j = 0; j < array.size(); j++) {
            if (mTurret[i]->getSprite().getGlobalBounds().contains(array.bullets[j].getX(), array.bullets[j].getY()) && mTurret[i]->checkHeal()) {
                mTurret[i]->hit(damage);
                array.pop(j);
            }
        }
    }
}

void Room::draw(RenderTarget &target, RenderStates states) const {
    for (int i = 0; i < mNumberOfTurret; i++) {
        target.draw(*mTurret[i], states);
    }
    for (int i = 0; i < mNumberOfWall; i++) {
        target.draw(*mWall[i], states);
    }
    target.draw(chest, states);
}

bool Room::characterHit(Character &character) {
    for (int i = 0; i < mNumberOfTurret; i++) {
        if (mTurret[i]->characterShot(character)) {
            return true;
        }
    }
    return false;
}

void Room::checkAndDrawBullets(MyQueue &myQueue, RenderWindow &window) {
    for (int i = 0; i < myQueue.size(); i++) {
        if (!(myQueue.bullets[i].checkWalls()) || !(myQueue.bullets[i].checkWalls(mWall))) {
            myQueue.pop(i);
        } else {
            myQueue.bullets[i].flying();
            window.draw(myQueue.bullets[i]);
        }
    }
}

void Room::turretAttack() {
    for (int i = 0; i < mNumberOfTurret; i++) {
        if (mWaitTurret[i] == 0) {
            mTurret[i]->attack();
            mWaitTurret[i] = 150;
        } else {
            mWaitTurret[i]--;
        }
        mTurret[i]->bulletFly(mWall);
    }
}

std::vector<Wall*> Room::getWall() {
    return mWall;
}

Image Room::getImage() {
    return mImage;
}

void Room::setChest(Vector2f position) {
    chest.setPosition(position);
}
