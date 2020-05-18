//
// Created by Ivan on 05.03.2020.
//

#include "Boss.h"
#include "World.h"
#include <iostream>

//Boss::Boss(float mX, float mY) {
//    mHeal = 50;
//    mDamage = 1;
//    texture.setRadius(100);
//    texture.setOrigin(10, 10);
//    texture.setPointCount(4);
//    texture.setFillColor(Color::Magenta);
//    texture.setPosition(mX, mY);
//    mX = mX;
//    mY = mY;
//}

void Boss::attack() {
    for (auto & i : mArray) {
        i.setPosition(mSprite.getPosition().x, mSprite.getPosition().y);
    }
    mArray[0].setDirection(5, 0);
    mArray[1].setDirection(5, -5);
    mArray[2].setDirection(0, -5);
    mArray[3].setDirection(-5, -5);
    mArray[4].setDirection(-5, 0);
    mArray[5].setDirection(-5, 5);
    mArray[6].setDirection(0, 5);
    mArray[7].setDirection(5, 5);
}

void Boss::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite, states);
    for (const auto & i : mArray) {
        target.draw(i, states);
    }
    for (const auto & i : mHP) {
        target.draw(i, states);
    }
}

Boss::Boss() {
    mHeal = 50;
    mDamage = 1;
    mTexture.loadFromFile("..\\programFiles\\Boss.png");
    mSprite.setOrigin(59, 51);
    mSprite.setTexture(mTexture);
    mSprite.setScale(0.5,0.5);
    mSprite.setPosition(0, 0);
    mX = 0;
    mY = 0;
    mHP[0].setSize(Vector2f(250, 25));
    mHP[0].setOutlineThickness(2);
    mHP[0].setOutlineColor(Color::Red);
    mHP[0].setFillColor(Color::Transparent);
    mHP[0].setPosition(300, 250);

    for (int i = 1; i < 51; i++) {
        mHP[i].setSize(Vector2f(5, 25));
        mHP[i].setFillColor(Color::Red);
        mHP[i].setPosition(300 + 5 * (i - 1.f), 250);
//        std::cout << mHP[i].getPosition().mX << ' ' << mHP[i].getPosition().mY << ' ' << i << ' ';
    }
//    std::cout << mHP[0].getPosition().mX;
}

void Boss::setPosition(float x, float y) {
    mX = x;
    mY = y;
    mSprite.setPosition(mX, mY);
}

void Boss::bulletFly(const std::vector<Wall*>& floor, World& world) {
    for (int i = 0; i < 51; i++) {
        if (mHeal < i) {
            mHP[i].setFillColor(Color::Transparent);
        }
    }
    for (auto & i : mArray) {
        if (i.checkWalls(floor) && i.checkWalls()) {
            i.flying();
        } else {
            i.setPosition(-200, -200);
        }
        if (i.checkCharacterShot(reinterpret_cast<Character &>(world.mCharacter)) && !world.mDefeat && world.mX == 1 && world.mY == 1) {
            world.mDefeat = true;
        }
    }

}

void Boss::hit(World& world) {
    for (int i = 0; i < world.mCharacter->weapon.bullets.size(); i++) {
        if (world.mCharacter->weapon.bullets.bullets[i].getSprite().getGlobalBounds().intersects(mSprite.getGlobalBounds())) {
            mHeal -= world.mCharacter->weapon.getDamage();
            std::cout << mHeal << " ";
            world.mCharacter->weapon.bullets.pop(i);
        }
    }
}

bool Boss::checkHeal() {
    return mHeal > 0;
}
