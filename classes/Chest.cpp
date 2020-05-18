//
// Created by Ivan on 23.04.2020.
//

#include "Chest.h"
#include "MachineGun.h"
#include "SubmachineGun.h"

Chest::Chest(Vector2f position) {
    mPosition = position;
    mSprite.setPosition(mPosition);
    mTexture.loadFromFile("..\\programFiles\\Chest.png");
    mSprite.setTexture(mTexture);
    mSprite.setScale(0.46875, 0.46875);
    mCollision.setSize(Vector2f(60, 60));
    mCollision.setPosition(mPosition.x - 15, mPosition.y - 15);
    int n = rand() % 4;
    if (n == 0) {
        mWeapons = new Gun();
    } else if (n == 1) {
        mWeapons = new Automatic();
    } else if (n == 2) {
        mWeapons = new MachineGun;
    } else {
        mWeapons = new SubmachineGun();
    }
    mSlot.setFillColor(sf::Color::Transparent);
    mSlot.setOutlineThickness(-1.5);
    mSlot.setOutlineColor(sf::Color::Red);
    mSlot.setSize(Vector2f(30, 30));
    mSlot.setPosition(mPosition);
    mWeaponSprite.setPosition(mPosition);
    mWeaponSprite.setTexture(mWeapons->texture);
    mWeaponSprite.setScale(0.5, 0.5);
    mBuffer.loadFromFile("..\\programFiles\\Chest.wav");
    mSound.setBuffer(mBuffer);
}

bool Chest::isOpen(Character character) {
    mIsOpen = mCollision.getGlobalBounds().intersects(character.getSprite().getGlobalBounds());
    return mIsOpen;
}

Weapons Chest::give() {
    mIsItBeOpen = true;
    mSound.play();
    return *mWeapons;
}

void Chest::draw(RenderTarget &target, RenderStates states) const {
    if (mIsOpen && !mIsItBeOpen) {
        target.draw(mSlot, states);
        target.draw(mWeaponSprite, states);
    } else {
        target.draw(mSprite, states);
    }
}

void Chest::setPosition(Vector2f position) {
    mPosition = position;
    mSprite.setPosition(mPosition);
    mCollision.setPosition(mPosition.x - 15, mPosition.y - 15);
    mSlot.setPosition(mPosition);
    mWeaponSprite.setPosition(mPosition + Vector2f(1.5, 1.5));
}

bool Chest::getIsItBeOpen() {
    return mIsItBeOpen;
}
