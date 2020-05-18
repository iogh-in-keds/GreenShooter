//
// Created by Ivan on 18.04.2020.
//


#include "Weapons.h"
#include "Character.h"

Weapons::Weapons() {
    mDamage = 0;
    mClib = 0;
    mRateOfFire = 0;
    mClibChange = 0;
    mAmmo = 0;
    mFont.loadFromFile("..\\programFiles\\comicbd.ttf");
    for (int i = 0; i < 12; i++) {
        bullets.bullets[i].setPosition(-200, -200);
        bullets.bullets[i].setDirection(0, 0);
    }
}

void Weapons::shot(Vector2f direction, Character character) {
    auto* bullet = new Bullet(float(character.getX() + 9.5), float(character.getY() + 9.5), direction.x, direction.y);
    bullets.push(*bullet);
    mAmmo--;
    delete(bullet);
}

float Weapons::getDamage() {
    return mDamage;
}

float Weapons::getWait() {
    if (mAmmo == 0) {
        return mClibChange;
    }
    return mRateOfFire;
}

void Weapons::setReloading(Vector2f position) {
    reloading.setPosition(position);
}

void Weapons::reloadUpdate() {
    if (mAmmo == 0) {
        mAmmo = mClib;
        reloading.setString("Reload");
    } else {
        reloading.setString(std::to_string(mAmmo));
    }
}

void Weapons::setAmmo(int newAmmo) {
    mAmmo = newAmmo;
}

int Weapons::getAmmo() {
    return mAmmo;
}

int Weapons::getClib() {
    return mClib;
}
