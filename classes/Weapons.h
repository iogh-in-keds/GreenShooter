//
// Created by Ivan on 18.04.2020.
//

#ifndef UNTITLED3_WEAPONS_H
#define UNTITLED3_WEAPONS_H


#include "Bullet.h"
#include "MyQueue.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Weapons {
public:

    Texture texture;

    Text reloading;

    float getWait();

    void setAmmo(int newAmmo);

    int getAmmo();

    void reloadUpdate();

    void setReloading(Vector2f position);

    Weapons();

    float getDamage();

    MyQueue bullets;

    int getClib();

    void shot(Vector2f direction, Character character);
protected:
    float mDamage;
    int mClib;
    float mRateOfFire;
    float mClibChange;
    int mAmmo;
    Font mFont;
};


#endif //UNTITLED3_WEAPONS_H
