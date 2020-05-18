//
// Created by Ivan on 23.04.2020.
//

#include "Inventory.h"
#include "MachineGun.h"
#include "SubmachineGun.h"

Inventory::Inventory() {
    for(int i = 0; i < 3; i++) {
        mObjects[i].setFillColor(sf::Color::Transparent);
        mObjects[i].setOutlineThickness(-1.5);
        mObjects[i].setOutlineColor(sf::Color::Red);
        mObjects[i].setSize(Vector2f(30, 30));
        mObjects[i].setPosition(float(300 + 30 * i), 700);
    }
    mInventory[0] = new Gun();
    mInventory[1] = new Automatic();
    mInventory[2] = new SubmachineGun();
    for(int i = 0; i < 3; i++) {
        mSprites[i].setPosition(mObjects[i].getPosition().x + float(1.5), mObjects[i].getPosition().y + float(1.5));
        mSprites[i].setScale(0.5, 0.5);
        mSprites[i].setTexture(mInventory[i]->texture);
    }
    object = *mInventory[mNumber];
    mObjects[mNumber].setOutlineColor(sf::Color::Green);
}

void Inventory::ChangeSlot(int delta) {
    mObjects[mNumber].setOutlineColor(sf::Color::Red);
    mNumber -= delta;
    if (mNumber == 3) {
        mNumber = 0;
    }
    if (mNumber == -1) {
        mNumber = 2;
    }
    object = *mInventory[mNumber];
    mObjects[mNumber].setOutlineColor(sf::Color::Green);
}

void Inventory::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < 3; i++) {
        target.draw(mObjects[i], states);
        target.draw(mSprites[i], states);
    }
}

void Inventory::chestGive(Weapons weapons) {
    *mInventory[mNumber] = weapons;
    object = *mInventory[mNumber];
    mSprites[mNumber].setTexture(mInventory[mNumber]->texture);
}

void Inventory::setPosition(Vector2f position) {
    for(int i = 0; i < 3; i++) {
        mObjects[i].setPosition(float(position.x + 30.f * float(i)), position.y);
    }
    for(int i = 0; i < 3; i++) {
        mSprites[i].setPosition(mObjects[i].getPosition().x + float(1.5), mObjects[i].getPosition().y + float(1.5));
    }
}

void Inventory::shotThis() {
    if (object.getAmmo() > 0) {
        object.setAmmo(object.getAmmo() - 1);
        *mInventory[mNumber] = object;
    } else {
        object.setAmmo(object.getClib());
        *mInventory[mNumber] = object;
    }
}

void Inventory::update() {
    object.reloadUpdate();
    mInventory[0]->reloadUpdate();
    mInventory[1]->reloadUpdate();
    mInventory[2]->reloadUpdate();
}
