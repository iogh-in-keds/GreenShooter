//
// Created by Ivan on 07.05.2020.
//

#include "SubmachineGun.h"

SubmachineGun::SubmachineGun() {
    mClib = 75;
    mDamage = 0.50;
    mRateOfFire = 0.1;
    mClibChange = 2;
    mAmmo = mClib;
    texture.loadFromFile("..\\programFiles\\PP.png");
    reloading.setFillColor(Color::Magenta);
    reloading.setFont(mFont);
    reloading.setString(std::to_string(mAmmo));
}
