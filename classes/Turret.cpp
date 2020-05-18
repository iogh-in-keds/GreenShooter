#include "Turret.h"

Turret::Turret(float heal, float damage, float x, float y) : Monster(heal, damage, x, y) {
    mHeal = heal;
    mDamage = damage;
    mX = x;
    mY = y;
    mSprite.setPosition(x, y);
    mIsBulletsDraw = true;
    mTexture.loadFromFile("..\\programFiles\\Turret.png");
    mSprite.setTexture(mTexture);
    mSprite.setScale(0.33, 0.33);
}

Turret::Turret() {
    mHeal = 1;
    mDamage = 1;
    mX = -100;
    mY = -100;
    mSprite.setPosition(mX, mY);
    mIsBulletsDraw = true;
    mTexture.loadFromFile("..\\programFiles\\Turret.png");
    mSprite.setTexture(mTexture);
    mSprite.setScale(0.33, 0.33);
}

void Turret::attack() {
    if (this->checkHeal()) {
        mBullet[0].setPosition(mX, mY + 12);
        mBullet[1].setPosition(mX + 30, mY + 12);
        mBullet[2].setPosition(mX + 12, mY);
        mBullet[3].setPosition(mX + 12, mY + 30);
        mBullet[0].setDirection(-10, 0);
        mBullet[1].setDirection(10, 0);
        mBullet[2].setDirection(0, -10);
        mBullet[3].setDirection(0, 10);
    } else {
        mIsBulletsDraw = false;
    }
}

void Turret::bulletFly(std::vector<Wall*> wall) {
    bool fly[4];
    fly[0] = true;
    fly[1] = true;
    fly[2] = true;
    fly[3] = true;
    for (int i = 0; i < 4; i++) {
        for (auto &j : wall) {
            if (j->getGlobalBounds().contains(mBullet[i].getX(), mBullet[i].getY())) {
                fly[i] = false;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (fly[i]) {
            mBullet[i].flying();
        } else {
            mBullet[i].setPosition(-1000, -1000);
        }
    }
    if (!mIsBulletsDraw) {
        for (auto &i : mBullet) {
            i.setPosition(-1000, -1000);
        }
    }
}

void Turret::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (this->checkHeal()) {
        target.draw(mSprite, states);
    }
    for (const auto &i : mBullet) {
        target.draw(i, states);
    }
}

bool Turret::characterShot(Character &character) {
    for (auto &i : mBullet) {
        if (character.getSprite().getGlobalBounds().contains(i.getX(), i.getY())) {
            return true;
        }
    }
    return false;
}

Sprite Turret::getSprite() {
    return mSprite;
}


