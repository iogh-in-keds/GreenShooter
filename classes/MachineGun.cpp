//
// Created by Ivan on 23.04.2020.
//

#include "MachineGun.h"

MachineGun::MachineGun() {
    mClib = 20;
    mDamage = 2;
    mRateOfFire = 0.06;
    mClibChange = 5;
    mAmmo = mClib;
    texture.loadFromFile("..\\programFiles\\MachineGun.png");
    reloading.setFillColor(Color::Magenta);
    reloading.setFont(mFont);
    reloading.setString(std::to_string(mAmmo));
}
