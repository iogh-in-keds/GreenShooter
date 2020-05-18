//
// Created by Ivan on 21.04.2020.
//

#include "Automatic.h"

Automatic::Automatic() {
    mClib = 50;
    mDamage = 0.75;
    mRateOfFire = 0.20;
    mClibChange = 1;
    mAmmo = mClib;
    texture.loadFromFile("..\\programFiles\\Automatic.png");
    reloading.setFillColor(Color::Magenta);
    reloading.setFont(mFont);
    reloading.setString(std::to_string(mAmmo));
}
