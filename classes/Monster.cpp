//
// Created by Ivan on 06.02.2020.
//

#include "Monster.h"

bool Monster::checkHeal() const {
    if (mHeal <= 0) {
        return false;
    }
    return true;
}

void Monster::hit(float damage) {
    mHeal -= damage;
}

Monster::Monster(float heal, float damage, float x, float y) {
    mHeal = heal;
    mDamage = damage;
    mX = x;
    mY = y;
//    mSprite.setRadius(15);
    mSprite.setPosition(x, y);
}

void Monster::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite);
}

Monster::Monster() {
    mHeal = 1;
    mDamage = 1;
    mX = -10;
    mY = -10;
//    mSprite.setRadius(15);
    mSprite.setPosition(mX, mY);
}
