//
// Created by Ivan on 18.04.2020.
//

#include "Gun.h"
#include "Character.h"

Gun::Gun() {
    mClib = 10;
    mDamage = 1;
    mRateOfFire = 0.5;
    mClibChange = 1.5;
    mAmmo = mClib;
    texture.loadFromFile("..\\programFiles\\Gun.png");
    reloading.setFillColor(Color::Magenta);
    reloading.setFont(mFont);
    reloading.setString(std::to_string(mAmmo));
}
